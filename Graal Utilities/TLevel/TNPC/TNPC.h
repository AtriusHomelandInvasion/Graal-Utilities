//
//  TNPC.h
//  Learning
//
//  Created by Matthew Warner on 5/5/15.
//  Copyright (c) 2015 Matthew Warner. All rights reserved.
//

#ifndef TNPC_H_
#define TNPC_H_

#include <iostream>
#include <vector>

class TNPC {
public:
    int x;
    int y;
    std::string imagefile;
    std::vector<std::string> line; // line[#] of the script ;)
    TNPC();
    ~TNPC();
private:
protected:
};

#endif /* defined(TNPC_H_) */
