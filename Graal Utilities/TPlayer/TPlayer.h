//
//  TPlayer.h
//
//  Created by Matthew Warner on 5/28/14.
//  Copyright (c) 2014 Matthew Warner. All rights reserved.
//

#ifndef TPLAYER_H_
#define TPLAYER_H_

#include <iostream>
#include "TWeapon.h"

class TPlayer {
public:
    const std::string account;          // Account name
    std::string nickname;               // Nickname
    float x;                            // Player.X
    float y;                            // Player.Y
    int hearts;                         // Hearts
    int fullhearts;                     // Max hearts
    std::string level;                  // Player.Level
    std::vector<TWeapon *> weapons;     // List of weapons the player has
    
    TPlayer(std::string acc);
    TPlayer();
    ~TPlayer();
    
    void heal();
    void hurt(int damage);
    void addweapon();
private:
protected:
};

#endif /* defined(TPLAYER_H_) */
