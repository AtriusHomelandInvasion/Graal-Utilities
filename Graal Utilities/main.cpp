//
//  main.cpp
//  Learning
//
//  Created by Matthew Warner on 10/15/14.
//  Copyright (c) 2014 Matthew Warner. All rights reserved.
//

#include "main.h"

// This is the main entry point of our program

int main(int argc, const char * argv[]) {
    TGmap gmap;
    gmap.load("levels/n-pulse.gmap");
    
    vector<string> list = GetGmapImages(&gmap);
    compareImagesToFiles(list);
    
    printf("Finished!\n");
 
    printf("Result:%s", gmap.levels[66]->name.c_str());
    
    return 0;
}

// this is needed for grabbing tokens out of strings :)

vector<string> Tokenize(string input, char delimiter) {
    vector<string> output;
    output.clear();
    stringstream buf(input);
    for(string token; getline(buf, token, delimiter); ) output.push_back(token);
    
    return output;
}

// Output 'images.txt' file with a list of all the images used in the npc's in the levels within the gmap.
// Any time a NPC image x y, is found it add's the image to the list if it's not already in the list. This will
// allow us to verrify all the level npc images are uploaded.

std::vector<string> GetGmapImages(TGmap *gmap) {
    vector<string> list; // list of images
    
    // loop thru all the levels
    for ( size_t k = 0; k < gmap->levels.size()-1; k ++ ) {
        
        // If we do not have any npc's to load, we can skip this part
        if ( gmap->levels[k]->npcs.size() < 1 ) continue;
        
        // Loop theu all the npc's in the level
        for ( size_t i = 0; i < gmap->levels[k]->npcs.size()-1; i ++ ) {
            
            int test = 0; // image not in the list
            
            // If our list is empty we dont need to check it
            if ( list.size() > 0 ) {
                // Check our list if it exists
                for ( size_t j = 0; j < list.size(); j ++ ) {
                    if ( gmap->levels[k]->npcs[i]->imagefile == list[j] ) test = 1; // image added to the list
                }
            }
            
            // Lets add to our list
            if ( test == 0 ) {
                list.push_back(gmap->levels[k]->npcs[i]->imagefile);
            }
        }
    }
    
    // Save list to file 'logs/images.txt'
    // This will overwrite the file, it will not append the data
    FILE * pFile;
    pFile = fopen("logs/images.txt", "wb");  // open file for write binary mode

    // If our list is not blank
    if ( list.size() > 0 ) {
        // Loop thru all the images in the list
        for ( size_t i = 0; i < list.size()-1; i++ ) {
            fprintf(pFile, "%s\n", list[i].c_str()); // write them to the file
        }
    }
    
    fclose(pFile);
    return list;
}

// this is to check if the file exists. if it does then the expected return is true, if not
// then false is returned to tell us it was not found.

bool fexists(string filename) {
    ifstream ifile(filename);
    if (ifile) {
        return 1;
    }
    return 0;
}

// This function goes thru a list of images, and checks the image folder if they exist
// if they don't it prints it back. This way we can find out which images still need to be
// added to the server

void compareImagesToFiles(vector<string> &list) {
    std::string fPath = "images/";
    vector<string> list2;
    
    for ( size_t i = 0; i < list.size()-1; i++ ) {
        if ( fexists(fPath + list[i].c_str()) == false ) {
            list2.push_back(list[i]);
        }
    }
    
    // Save list to file 'logs/images.txt'
    // This will overwrite the file, it will not append the data
    FILE * pFile;
    pFile = fopen("logs/missing-images.txt", "wb");  // open file in write binary mode
    
    // If our list is not blank
    if ( list.size() > 0 ) {
        // Loop thru all the images in the list
        for ( size_t i = 0; i < list2.size()-1; i++ ) {
            if ( ! strcmp(list2[i].c_str(), "-") ) continue; // skip if image is "-"
            fprintf(pFile, "file %s not found.\n", list2[i].c_str()); // write them to the file
        }
    }
    
    // close the file, otherwise we end up with memory leaks.
    fclose(pFile);
}

// Usefull for extractng the file path from a file :) We will use this to tell the TGmap tell the TLevel where
// to load it's level from. In the future maybe we can update indivual paths for example if we did an SDK.

string extractPath(string path) {
    for ( size_t i = path.size()-1; i > 0; i -- ) {
        if ( path.substr(i, 1) == "/" ) {
            return path.substr(0, i + 1); // Copy everything until the last "/"
        }
    }
    return ""; // no folder
}