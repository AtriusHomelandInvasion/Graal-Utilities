//
//  main.h
//  Learning
//
//  Created by Matthew Warner on 5/5/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#ifndef MAIN_H_
#define MAIN_H_

#include "TTile.h"
#include "TChest.h"
#include "TNPC.h"
#include "TLink.h"
#include "TSign.h"
#include "TLevel.h"
#include "TGmap.h"
#include "TWeapon.h"
#include "TPlayer.h"
#include "TBaddy.h"
#include "TGani.h"
#include "TSprite.h"

string extractPath(string path);

#endif  /* defined(MAIN_H_) */

/*
 body    bodies/*.png
 head    heads/*
 sword   swords/*
 shield  shields/*
 level   *.graal
 level   *.nw
 level   *.gmap
 file    *.png
 file    *.mng
 file    *.gif
 file    *.gani
 file    *.wav
 file    *.txt
 file    *.gmap
 file    images/*.png
 file    images/*.gif
 file    images/*.mng
 
 level   overworld/*.graal
 level   overworld/*.nw
 level   overworld/*.gmap
 level   insides/*.graal
 level   insides/*.nw
 level   insides/*.gmap
 level   events/*.graal
 level   events/*.nw
 level   events/*.gmap
 level   quests/*.graal
 level   quests/*.nw
 level   quests/*.gmap
 file    ganis/*.gani
 level   gmaps/*.gmap
 file    gmaps/*.gmap
*/