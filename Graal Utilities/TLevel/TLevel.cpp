//
//  TLevel.cpp
//
//  Created by Matthew Warner on 5/28/14.
//  Copyright (c) 2014 Matthew Warner. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "TLevel.h"

using namespace std;

// this is needed for opening nw format levels and handling tiles
string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// this is needed for grabbing tokens out of strings :)
vector<string> Tokenize(string input, char delimiter) {
    vector<string> output;
    output.clear();
    stringstream buf(input);
    for(string token; getline(buf, token, delimiter); ) output.push_back(token);
    
    return output;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Constructors / Destructors
////////////////////////////////////////////////////////////////////////////////////////////

TLevel::TLevel() {
    this->name = "new1.nw";          // our default level name will be new#.nw
    
    // this will generate a blank board with no links
    for ( int i = 0; i < 64; i ++ ) {
        //this->tile[i].setTile(0);
    }
}

TLevel::~TLevel() {
    // destroy all the tiles, links, ect associated with this level
    // i think this is done automatically tho
}

////////////////////////////////////////////////////////////////////////////////////////////
// TLevel loadlevel function
//
// Only load levels using this funciton.. It will automatically load the rest and avoid any
// problems that may occur.
//
////////////////////////////////////////////////////////////////////////////////////////////

bool TLevel::loadLevel(string filePath) {
    this->name = filePath;                          // still need to extract filename from filePath
    FILE *file = fopen(filePath.c_str(), "rb");     // open file in read binary mode
    if ( file != NULL ) {                           // make sure we can open file
        char fileBuf[9];                            // we need a buffer to load our data into
        fread(fileBuf, 8, 1, file);                 // read out file header to determin level version
        string header(fileBuf);                     // this is what type of file we are working with

        // header versions
        if ( header == "GLEVNW01" ) { this->loadNW(filePath);   return true; }   // nw level
        if ( header == "GR-V1.01" ) { this->loadGraal(file, 1); return true; }   // version 1
        if ( header == "GR-V1.02" ) { this->loadGraal(file, 2); return true; }   // version 2
        if ( header == "GR-V1.03" ) { this->loadGraal(file, 3); return true; }   // version 3
        if ( header == "Z3-V1.03" ) { this->loadZelda(file);    return true; }   // version 3 this might be able to load off .graal
        if ( header == "Z3-V1.04" ) { this->loadZelda(file);    return true; }   // version 4 this might be able to load off .graal
        return false;   // we did not recognise the level header
    }
    return false;       // no level was found
}

// This still needs to be completely re-written to be much
// cleaner code and optimized to run effeciently.
bool TLevel::loadNW(string filePath) {
    ifstream in_stream;
    string line;
    in_stream.open(filePath);
    
    int mode = 0;
    
    while( !in_stream.eof() ) {
        getline(in_stream, line);
        
        vector<string> v;
        stringstream buf(line);
        for(string token; getline(buf, token, ' '); ) v.push_back(token);
        
        // load tile's from board
        if ( line.substr(0,5) ==  "BOARD" ) {
            for ( int i = 0; i < 64; i++ ) {
                unsigned long tile = (base64.find(v[5].substr(i*2,1).c_str()) * 64) + (base64.find(v[5].substr(i*2+1,1).c_str()));
                int y = atoi(v[2].c_str());
                this->tile[y * 64 + i] = (int)tile;
            }
        }
        
#ifdef TLINK_H_
        // load links from board
        if ( line.substr(0,4) == "LINK" ) {
            TLink link;
            link.level  = v[1].c_str();
            link.srcX   = atoi(v[2].c_str());
            link.srcY   = atoi(v[3].c_str());
            link.width  = atoi(v[4].c_str());
            link.height = atoi(v[5].c_str());
            link.destX  = atoi(v[6].c_str());
            link.destY  = atoi(v[7].c_str());
            this->links.push_back(new TLink(link));
        }
#endif
        
        // CHEST - depricated
        // I can make it read all my sign's and append them to the file as npc's :)
        // and join them to a custom class lol
        // this.join("chest");
        // this.item = "bomb";
        // this.quantity = 1;
        // etc
        
#ifdef TCHEST_H_
        if ( line.substr(0,5) == "CHEST" ) {
            TChest chest;
            chest.x = atoi(v[1].c_str());
            chest.y = atoi(v[2].c_str());
            chest.item = v[3].c_str();
            chest.unknown = atoi(v[4].c_str());
            this->chests.push_back(new TChest(chest));
        }
#endif
        
#ifdef TBADDY_H_
        if ( line.substr(0,5) == "BADDY" ) {
            TBaddy baddy;
            baddy.x = atoi(v[1].c_str());
            baddy.y = atoi(v[2].c_str());
            baddy.index = atoi(v[3].c_str());
            this->baddys.push_back(new TBaddy(baddy));
        }
#endif
        
#ifdef TSIGN_H_
        if ( line.substr(0,7) == "SIGNEND" ) {
            mode = 0;
        }
        
        // We are reading signs, we read the messages into an array and then add a pointer to the sign object
        // to the level to point to the sign.
        if ( mode == 2 ) {
            this->signs[this->signs.size()-1]->messages.push_back(line);
        }
        
        if ( line.substr(0,4) == "SIGN" && line.substr(0,7) != "SIGNEND") {
            TSign sign;
            sign.x = atoi(v[1].c_str());
            sign.y = atoi(v[2].c_str());
            this->signs.push_back(new TSign(sign));
            mode = 2;
        }
#endif
        
#ifdef TNPC_H_
        if ( line.substr(0,6) == "NPCEND" ) {
            mode = 0;
        }
      
        if ( mode == 3 ) {
            this->npcs[this->npcs.size()-1]->line.push_back(line);
        }
        
        if ( line.substr(0,3) == "NPC" && line.substr(0,6) != "NPCEND") {
            TNPC npc;
            npc.x = atoi(v[2].c_str());
            npc.y = atoi(v[3].c_str());
            npc.imagefile = v[1].c_str();
            this->npcs.push_back(new TNPC(npc));
            mode = 3;
        }
#endif
    }
    
    in_stream.close();
    return 1;
}

bool TLevel::loadZelda(FILE *file) {
    // this might be the same as .graal format, still need to check
    return 0;
}
    
// needs some adjustments but it works well
// maybe use bits instead of version, will shorten code if we do
bool TLevel::loadGraal(FILE *file, int version) {
    char fileBuf[2];                        // allow us a 16 bit buffer
    int bits = (version > 0 ? 13 : 12);     // find out how many bits we need to read
    int read = 0;                           // how many bits we have read so far
    
    unsigned int buffer = 0;                // another needed buffer
    unsigned short code = 0;                // some code thinggy we need

    short tiles[2] = {-1,-1};               // value of the tiles
    int count = 1;                          // dunno
    bool doubleMode = false;                // dunno
    int boardIndex = 0;                     // current tile

    while ( boardIndex < 4096 ) {
        while ( read < bits ) {
            fread(fileBuf, 1, 1, file);
            buffer += (unsigned char)*fileBuf << read;
            read += 8;
        }
        code = buffer & (bits == 12 ? 0xFFF : 0x1FFF);
        buffer >>= bits;
        read -= bits;
        
        // See if we have an RLE control code.
        // Control codes determine how the RLE scheme works.
        if (code & (bits == 12 ? 0x800 : 0x1000)) {
            
            // If the 0x100 bit is set, we are in a double repeat mode.
            // {double 4}56 = 56565656
            if (code & 0x100) doubleMode = true;
            
            // How many tiles do we count?
            count = code & 0xFF;
            continue;
        }

        // If our count is 1, just read in a tile.  This is the default mode.
        if (count == 1) {
            //this->tile[boardIndex].setTile((short)code);
            boardIndex ++;
            continue;
        }
        
        // If we reach here, we have an RLE scheme.
        // See if we are in double repeat mode or not.
        if (doubleMode) {
            // Read in our first tile.
            if (tiles[0] == -1) {
                tiles[0] = (short)code;
                continue;
            }
            
            // Read in our second tile.
            tiles[1] = (short)code;
            
            // Add the tiles now.
            for (int i = 0; i < count && boardIndex < 4095; ++i) {
                //this->tile[boardIndex/64][boardIndex%64].setTile(tiles[0]);
                boardIndex ++;
                //this->tile[boardIndex/64][boardIndex%64].setTile(tiles[1]);
                boardIndex ++;
            }
            
            // Clean up.
            tiles[0] = tiles[1] = -1;
            doubleMode = false;
            count = 1;
        }
        // Regular RLE scheme.
        else {
            for (int i = 0; i < count && boardIndex < 4096; ++i) {
                //this->tile[boardIndex/64][boardIndex%64].setTile((short)code);
                boardIndex ++;
            }
            count = 1;
        }
    }
    
    // now on to links and everything else
    //
    
    //this->saveNW(); // this will save only the tiles from our .graal level
    return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Save Level
////////////////////////////////////////////////////////////////////////////////////////////

// Graal NW format
bool TLevel::saveNW() {
    FILE * pFile;
    pFile = fopen("output.txt", "wb");  // open file for write binary mode
    fprintf(pFile, "GLEVNW01\n");       // Header for NW level format
    
    // TILES
    for ( int y = 0; y < 64; y ++ ) {
        fprintf(pFile, "BOARD %d %d %d %d ", 0, y, 64, 0);
        for ( int x = 0; x < 64; x ++ ) {
            //fprintf(pFile, "%s", this->tile[y * 64 + x].getBase64().c_str());
        }
        fprintf(pFile, "\n");           // goto next line
        
    }
    
    // LINKS
    // fprintf("LINK %s %s %s %s %s %s %s\n", level, x, y, w, h, ex, ey);
    
    // NPCS
    // fprintf("NPC %s %d %d\n", imagename, x, y);
    // NPC DATA HERE
    // fprintf("NPCEND\n");
    
    // SIGNS
    // fprintf("SIGN\n");
    // SIGN DATA HERE
    // fprintf("SIGNEND\n");
    
     // ect
    
    fclose(pFile); // close our file
    return 1;
}

bool TLevel::saveGRAAL(FILE *file) {
    return 1;
}

bool TLevel::saveZELDA(FILE *file) {
    return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////
// TTile functions
////////////////////////////////////////////////////////////////////////////////////////////

// sets our tile
void TTile::setTile(int tile) {
    this->tile = tile; // integer value of the current tile
    this->xpos = this->tile/512*16 + (this->tile%512)%16;
    this->ypos = (this->tile%512)/16;
}

// get the base64 string of the tile, for use with nw levels
//string TTile::getBase64() {
//    return base64.substr(this->tile/64,1) + base64.substr(this->tile%64,1);
//}