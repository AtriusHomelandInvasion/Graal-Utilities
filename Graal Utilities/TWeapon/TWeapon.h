//
//  TWeapon.h
//  test
//
//  Created by Matthew Warner on 8/5/14.
//  Copyright (c) 2014 Matthew Warner. All rights reserved.
//

#ifndef TWEAPON_H_
#define TWEAPON_H_

#include <iostream>
#include <vector>

class TWeapon;

class TWeapon {
public:
    std::string image;             // Image for the weapon in inventory and hud
    std::vector<std::string> line; // The script
    TWeapon();
    ~TWeapon();
private:
protected:
};

#endif /* defined(TWEAPON_H_) */
