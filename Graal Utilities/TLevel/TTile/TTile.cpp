//
//  TTile.cpp
//  Learning
//
//  Created by Matthew Warner on 5/5/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#include "TTile.h"

TTile::TTile() {}

TTile::~TTile() {}

// This function takes an int, and assigns the value to the tile. It then calculates the position
// on the tileset you would find that tile.

void TTile::setTile(int tile) {
    this->tile = tile; // integer value of the current tile
    this->xpos = (int)tile/512*16 + (tile%512)%16;
    this->ypos = (tile%512)/16;
}