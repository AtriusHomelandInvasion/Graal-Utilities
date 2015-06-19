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
#include "TLayer.h"

#include <iostream>
#include <dirent.h>

string extractPath(string path);    // input: "levels/images/file.ext", output: "levels/images/"
vector<string> Tokenize(string input, char delimiter);
std::vector<string> GetGmapImages(TGmap *gmap);
void compareImagesToFiles(vector<string> &list);

#endif  /* defined(MAIN_H_) */