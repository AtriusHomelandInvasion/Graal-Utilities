//
//  TGmap.h
//  Learning
//
//  Created by Matthew Warner on 5/5/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#ifndef TGMAP_H_
#define TGMAP_H_

#include <iostream>
#include <vector>
#include <stdio.h>
#include "TLevel.h"

/*
 
 TGMAP Variables:
 
 header     // gmap version. GRMAP001
 path       // file path so we can find level on hard disk incase we need to reload it
 name       // so we know if we are on the map or not
 width      // so we can determin x/y cords on the map
 height     // so we can determin x/y cords on the map
 levels     // all the level data
 
 */


class TGmap {
public:
    std::string name; // name of our gmap :)
    std::vector<TLevel *> levels; // levels within the gmap
    int height;
    int width;
    std::string minimap;
    TGmap();
    ~TGmap();
    
    // load gmap
    bool load(const char* filePath);
};

#endif /* defined(TGMAP_H_) */