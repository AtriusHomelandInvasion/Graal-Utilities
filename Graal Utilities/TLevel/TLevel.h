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
#include "TTile.h"
#include "TChest.h"
#include "TNPC.h"
#include "TLink.h"
#include "TSign.h"
#include "TBaddy.h"

using namespace std;

class TLevel;

vector<string> Tokenize(string input, char delimiter);

////////////////////////////////////////////////////////////////////////////////////////////
// Declare our custom classes
////////////////////////////////////////////////////////////////////////////////////////////

class TLevel {
public:
    //int tiledata[4096]; // per layer
    int tile[4096];
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
