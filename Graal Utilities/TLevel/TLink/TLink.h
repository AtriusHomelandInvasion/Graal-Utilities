//
//  TLink.h
//  Learning
//
//  Created by Matthew Warner on 5/5/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#ifndef TLINK_H_
#define TLINK_H_

#include <iostream>

class TLink {
public:
    std::string level;
    int srcX;
    int srcY;
    int width;
    int height;
    int destX;
    int destY;
    TLink();
    ~TLink();
};

#endif /* defined(TLINK_H_) */
