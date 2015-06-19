//
//  TGani.h
//  Graal Utilities
//
//  Created by Matthew Warner on 5/7/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#ifndef TGANI_H_
#define TGANI_H_

#include <iostream>
#include <vector>
#include "TSprite.h"

// We need to have sprites which are images, or part of the image then we need cords to display them at. We also
// need to know when we will be moving things around, showing more things, showing less things. We can accomplish
// this by frames.. TFrames ?? (maybe!)

class TFrame {
public:
    std::vector<TSprite *>sprites;
    int duration; // in milliseconds (1000 = 1 second)
private:
protected:
};

class TGani {
public:
    std::string filename;
    bool ganiMovie;
    
    TGani();
    ~TGani();
private:
protected:
};

#endif /* defined(TGANI_H_) */
