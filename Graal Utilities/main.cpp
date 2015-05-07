//
//  main.cpp
//  Learning
//
//  Created by Matthew Warner on 10/15/14.
//  Copyright (c) 2014 Matthew Warner. All rights reserved.
//

#include <iostream>
#include "main.h"

int main(int argc, const char * argv[]) {
    TGmap gmap;
    gmap.load("n-pulse.gmap");
    
    // WARNING: DON'T ACCESS VARIABLES THAT DO NOT EXIST YET
    //          WILL CAUSE A CRASH !!!
    
    // Loop thru and list all the images used :)
    
    vector<string> list;
    
    for ( int k = 0; k < gmap.levels.size()-1; k ++ ) {
        if ( gmap.levels[k]->npcs.size() < 1 ) continue;
        for ( int i = 0; i < gmap.levels[k]->npcs.size()-1; i ++ ) {
            int test = 0;
        
            // If our list is empty we dont need to check it
            if ( list.size() > 0 ) {
                // Check our list if it exists
                for ( int j = 0; j < list.size(); j ++ ) {
                    if ( gmap.levels[k]->npcs[i]->imagefile == list[j] ) test = 1;
                }
            }
        
            // Lets add to our list
            if ( test == 0 ) {
                list.push_back(gmap.levels[k]->npcs[i]->imagefile);
            }
        }
    }
    
    
    cout << gmap.levels.size() << " levels." << endl;
    //cout << gmap.levels[66]->name << endl;
    //cout << gmap.levels[66]->signs[0]->messages[0] << endl;
    //cout << gmap.levels[66]->chests[0]->item << endl;
    //cout << gmap.levels[66]->npcs[2]->line[1] << endl;
    
    //this is a changein the code, woo.
    //this is another change..?
    // deas changed this.
}