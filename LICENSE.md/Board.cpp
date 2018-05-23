#include "Board.h"
using namespace std;

/*
*Default Constructor
*/
Board::Board(){
    this->len=1;
    this->brd=new Sign*[1];
    for(int i=0;i<1;++i){
        this->brd[i]=new Sign[1];
    }
}
Board::Board(int len){
    this->len=len;
    this->brd=new Sign*[len];
    for(int i=0;i<len;++i){
        this->brd[i]=new Sign[len];
    }
}
/*
*Copy Constructor
*/
Board::Board(const Board& other){
    this->len=other.len;
    this->brd=new Sign*[other.len];
    for(int i=0;i<other.len;++i){
        this->brd[i]=new Sign[other.len];
        for(int j=0;j<other.len;++j){
           this->brd[i][j]=other.brd[i][j];
        }
    }
}
/*
*Return size
*/
 uint Board:: size()const{return this->len;}
/*
*Opreator to return Sign in Some Cooridnate
*/
Sign& Board:: operator[](const Coordinate& cor)const {
    if(cor.GetRow()<len&&cor.GetColumn()<len)
        return brd[cor.GetRow()][cor.GetColumn()];
    throw IllegalCoordinateException (cor.GetRow(),cor.GetColumn());
}
/*
*Opreator input to Change Sign in the Board
*/
Board& Board:: operator=(const char& c){
    for(int i=0;i<len;++i){
        for(int j=0;j<len;++j){
            this->brd[i][j]=c;
        }
    }
    return *this;
}
/*
*Operator input to change the Board to other
*/
Board& Board:: operator=(const Board& b){
    this->~Board();
    this->len=b.len;
    this->brd=new Sign*[len];
    for(int i=0;i<len;++i){
        this->brd[i]=new Sign[len];
        for(int j=0;j<len;++j){
           this->brd[i][j]=b.brd[i][j];
        }
    }
    return *this;
}
/*
*Destractor
*/
Board::~Board(){
    for(int i=0;i<this->len;++i){
        delete[] brd[i];
    }
    delete[] brd;
}
