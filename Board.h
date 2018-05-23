#pragma once

#include <iostream>
#include "Sign.hpp"
#include "Coordinate.hpp"
#include "IllegalCoordinateException.hpp"

using namespace std;

class Board{
/*
*Declarence of varible
*/    
    int len;
    Sign** brd;
/*
*Declarence on function
*/    
public:
     uint size()const;
    Board(int);
    Board();
    Board(const Board& other);
    Sign& operator[](const Coordinate&) const;
    Board& operator=(const char& c);
    Board& operator=(const Board&);
    friend ostream& operator<< (ostream& out, const Board &b);
    ~Board();
};
/*
*Print the Board
*/
inline ostream&  operator<< (ostream& out, const Board &b){
    for(int i=0;i<b.len;++i){
        for(int j=0;j<b.len;++j){
            out <<b.brd[i][j];
        }
        out << '\n';
    }
   
    return out;

}
