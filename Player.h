#pragma once

#include <iostream>

#include "Board.h"
using namespace std;
 class Player {
/*
*Declarence of varible
*/   
    public:
    char myChar;
/*
*Declarence on function
*/     
     virtual const string name()const{return "Player";}
     virtual const Coordinate play(const Board& Board)=0;
     const char getChar() const;
     void setChar(char c);
};
