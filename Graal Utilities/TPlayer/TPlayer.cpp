//
//  TPlayer.cpp
//
//  Created by Matthew Warner on 5/28/14.
//  Copyright (c) 2014 Matthew Warner. All rights reserved.
//

#include "TPlayer.h"

#define FULLHEARTS 3
#define STARTX 30
#define STARTY 30

TPlayer::TPlayer(std::string acc)
:account(acc)   // This makes it so you can't change the account of the player object after created
{
    // default data
    this->nickname = "unknown";
    //this->guild = "(Storm)"; // for scriptless and drako ;)
    this->fullhearts = FULLHEARTS; // default player starts with 3 hearts
    this->hearts = this->fullhearts;
    this->x = STARTX;
    this->y = STARTY;
}

//So we don't need (""); at the end of all our variables
TPlayer::TPlayer() {
    TPlayer::TPlayer("");
}

// destructor
TPlayer::~TPlayer() {
    // not sure when this function is called
}

// This is a test weapon added to the player. I think it will just send the clientside code to the client
// and the client can just read and execute maybe?

void TPlayer::addweapon() {
    
    // Normally we won't need to create a weapon, we will just load one that is sent to us
    // and add that.
    TWeapon weapon;
    weapon.image = "door.png";
    weapon.line.push_back("//#CLIENTSIDE");
    weapon.line.push_back("function onCreated(){");
    weapon.line.push_back("  player.chat = \"works\"");
    weapon.line.push_back("}");
    
    // Add the weapon to the player
    this->weapons.push_back(new TWeapon(weapon));
}

// heal the player
void TPlayer::heal() {
    this->hearts = this->fullhearts;
}

// allow us to hurt the player
void TPlayer::hurt(int damage) {
    
    // we must do at least 1 damage
    if ( damage <= 0 ) damage = 1;
    
    if ( this->hearts > 0 )
        this->hearts -= damage;
    
    if ( this->hearts - damage <= 0 ) {
        // player is dead
        this->hearts = 0; // so we don't show a negative heart value
    }
}