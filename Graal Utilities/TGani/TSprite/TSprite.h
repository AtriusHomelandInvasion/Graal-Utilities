//
//  TSprite.h
//  Graal Utilities
//
//  Created by Matthew Warner on 5/7/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#ifndef TSPRITE_H_
#define TSPRITE_H_

#include <iostream>

class TSprite {
public:
    std::string filename;
    std::string description;
    int x;
    int y;
    int partx;
    int party;
    int width;
    int height;
    
    TSprite();
    ~TSprite();
private:
protected:
};

#endif /* defined(TSPRITE_H_) */
