//
//  main.cpp
//  Learning
//
//  Created by Matthew Warner on 10/15/14.
//  Copyright (c) 2014 Matthew Warner. All rights reserved.
//

#include <iostream>
#include "main.h"

// Output 'images.txt' file with a list of all the images used in the npc's in the levels within the gmap.
// Any time a NPC image x y, is found it add's the image to the list if it's not already in the list. This will
// allow us to verrify all the level npc images are uploaded.

void GetGmapImages(TGmap *gmap) {
    // Loop thru and list all the images used :)
    
    vector<string> list;
    
    for ( int k = 0; k < gmap->levels.size()-1; k ++ ) {
        if ( gmap->levels[k]->npcs.size() < 1 ) continue;
        for ( int i = 0; i < gmap->levels[k]->npcs.size()-1; i ++ ) {
            int test = 0;
            
            // If our list is empty we dont need to check it
            if ( list.size() > 0 ) {
                // Check our list if it exists
                for ( int j = 0; j < list.size(); j ++ ) {
                    if ( gmap->levels[k]->npcs[i]->imagefile == list[j] ) test = 1;
                }
            }
            
            // Lets add to our list
            if ( test == 0 ) {
                list.push_back(gmap->levels[k]->npcs[i]->imagefile);
            }
        }
    }
    
    // Save list to file 'logs/images.txt'
    FILE * pFile;
    pFile = fopen("logs/images.txt", "wb");  // open file for write binary mode
    
    if ( list.size() > 0 ) {
        for ( int i = 0; i < list.size()-1; i++ ) {
            fprintf(pFile, "%s\n", list[i].c_str());
        }
    }
    
    fclose(pFile);
}

// Usefull for extractng the file path from a file :) We will use this to tell the TGmap tell the TLevel where
// to load it's level from. In the future maybe we can update indivual paths for example if we did an SDK.

string extractPath(string path) {
    for ( int i = (int)path.size()-1; i > 0; i -- ) {
        if ( path.substr(i, 1) == "/" ) {
            return path.substr(0, i) + "/";
        }
    }
    return "";
}

int main(int argc, const char * argv[]) {
    TGmap gmap;
    gmap.load("levels/n-pulse.gmap");
    
    // This function will make a file 'logs/images.txt' listing all the images used in the levels
    GetGmapImages(&gmap);
    
    // WARNING: DON'T ACCESS VARIABLES THAT DO NOT EXIST YET
    //          WILL CAUSE A CRASH !!!
    
    //cout << gmap.levels.size() << " levels." << endl;
    //cout << gmap.levels[66]->name << endl;
    //cout << gmap.levels[66]->signs[0]->messages[0] << endl;
    //cout << gmap.levels[66]->chests[0]->item << endl;
    //cout << gmap.levels[66]->npcs[2]->line[1] << endl;
    
    printf("Finished!\n");
}