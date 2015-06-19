//
//  TLevel.h
//
//  Created by Matthew Warner on 5/28/14.
//  Copyright (c) 2014 Matthew Warner. All rights reserved.
//

#ifndef TLEVEL_H_
#define TLEVEL_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "TTile.h"
#include "TChest.h"
#include "TNPC.h"
#include "TLink.h"
#include "TSign.h"
#include "TBaddy.h"
#include "TTile.h"
#include "TLayer.h"

using namespace std;

// We need to list them like this so other cpp files can access them
// otherwise they wont know they even exist
string getBase64(int tile);

class TLevel {
public:
    TTile tile[4096];              // Tiles, no LAYER ?!? support yet
    std::vector<TLayer *>layers;   // Layer support :)
    std::vector<TLink *> links;    // links within the level
    std::vector<TSign *> signs;    // signs within the level
    std::vector<TNPC *> npcs;      // npcs within the level
    std::vector<TChest *> chests;  // schests within the level
    std::vector<TBaddy *> baddys;  // baddies within the level

    std::string name; // level name (its the filename basically)
    TLevel();
    ~TLevel();
    
    // save functions
    bool saveNW();
    bool saveGRAAL(FILE *file);
    bool saveZELDA(FILE *file);
    
    // load level functions
    bool loadLevel(string filePath);
private:
    bool loadGraal(FILE *file, int version);
    bool loadZelda(FILE *file);
    bool loadNW(string filePath);
protected:
};

#endif /* defined(TLEVEL_H_) */
