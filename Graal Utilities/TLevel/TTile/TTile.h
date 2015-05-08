//
//  TTile.h
//  Learning
//
//  Created by Matthew Warner on 5/5/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#ifndef TTILE_H_
#define TTILE_H_

class TTile {
public:
    unsigned long tile;
    int xpos;               // 'x' position on the tileset
    int ypos;               // 'y' position on the tileset
    void setTile(int tile); // needed to set the tile
    TTile();
    ~TTile();
private:
protected:
};


#endif /* defined(TTILE_H_) */
