/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef _KINGDOM_H
#define _KINGDOM_H
#include <iostream>

#define MAX_CHAR 32
using namespace std;

namespace sict {

    struct Kingdom {
        char m_name [MAX_CHAR];
        int m_population;
    };
 
    void display(const Kingdom &kingdom);
    void display(const Kingdom *kingdom, int amount);
}
#endif