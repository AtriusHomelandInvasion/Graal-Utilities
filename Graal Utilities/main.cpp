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
    
    cout << gmap.levels.size() << " levels." << endl;
    //cout << gmap.levels[66]->name << endl;
    //cout << gmap.levels[66]->signs[0]->messages[0] << endl;
    //cout << gmap.levels[66]->chests[0]->item << endl;
    //cout << gmap.levels[66]->npcs[2]->line[1] << endl;
    
    //this is a changein the code, woo.
    //this is another change..?
}