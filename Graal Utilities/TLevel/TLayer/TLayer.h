//
//  TLayer.h
//  Graal Utilities
//
//  Created by Matthew Warner on 5/7/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#ifndef TLAYER_H_
#define TLAYER_H_

#include "TTile.h"

class TLayer {
public:
    TTile tile[4096];   // 1 level worth of tiles
    TLayer();
    ~TLayer();
};

#endif /* defined(TLAYER_H_) */
