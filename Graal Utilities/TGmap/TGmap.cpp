//
//  TGmap.cpp
//  Learning
//
//  Created by Matthew Warner on 5/5/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#include "TGmap.h"
#include "TLevel.h"
#include "main.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>

TGmap::TGmap() {}

TGmap::~TGmap() {}

////////////////////////////////////////////////////////////////////////////////////////////
// GMAP functions
////////////////////////////////////////////////////////////////////////////////////////////

bool TGmap::load(const char* filePath) {
    std::string line;
    
    //the variable of type ifstream:
    ifstream myfile (filePath);
    
    //check to see if the file is opened:
    if (myfile.is_open())
    {
        // Check header
        getline (myfile,line);
        if ( line != "GRMAP001" ) return 0;
        
        int mode = 0; // we need to know if we hit one of our commands
        // then start reading data untill told to stop
        
        // while there are still lines in the
        // file, keep reading:
        while (! myfile.eof() )
        {
            // place the line from myfile into the
            // line variable:
            getline (myfile, line);
            
            if ( line.substr(0, 6) == "HEIGHT" )  this->height  = atoi(line.substr(6, -1).c_str());
            if ( line.substr(0, 5) == "WIDTH" )   this->width   = atoi(line.substr(5, -1).c_str());
            if ( line.substr(0, 10) == "MINIMAPIMG" ) this->minimap = line.substr(11, -1).c_str();
            
            if ( line.substr(0, 13) == "LEVELNAMESEND" ) mode = 0;
            
            std::vector<string> test(Tokenize(line, ','));
            
            // We need to know that were reading levels, not just that mode == 1, this needs updated
            if ( mode == 1 && line != "" ) {
                for ( int i = 0; i < test.size(); i++ ) {
                    TLevel newLevel;
                    newLevel.name = test[i].substr(1,test[i].length()-2);
                    newLevel.loadLevel(extractPath(filePath) + newLevel.name);
                    this->levels.push_back(new TLevel(newLevel));
                }
            }
            
            if ( line.substr(0, 10) == "LEVELNAMES" ) mode = 1;
            
        }
        
        // close the stream:
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    return 0;
}