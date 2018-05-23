#include "TicTacToe.h"

#include <iostream>
using namespace std;
/*
*Constructor
*/
TicTacToe:: TicTacToe(int len)  {
    Board other(len);
    this->brd=other;
    }
/*
*Print the game
*/   
void TicTacToe:: print()  {
    cout<<this->brd<<endl;
}
/*
*Return the table
*/
Board TicTacToe:: board() const{
    return brd;
}
/*
*Function for actual game always check if there is a winner
*/
void TicTacToe:: play(Player& x, Player& o) {
    //Intilize board
    for(uint i=0;i<brd.size();++i){
        for(uint j=0;j<brd.size();++j){
           this->brd[{i,j}]='.';
        }
    }
    x.setChar('X');
    o.setChar('O');
    int count=0;
    while(count<this->brd.size()*this->brd.size()){
        Coordinate c;
        try{
            c=x.play(this->brd);
            if (c.GetRow()>=brd.size()||c.GetColumn()>=brd.size()||this->brd[c]!='.'){
                throw std::string("Illegal Move");
            }
        }
        catch(...){
            *win=o;
            return;
        }
      this->brd[c]='X'; 
       if(check(c)){
           win=&x;
           return;
       }
       count++;
       if(count>=this->brd.size()*this->brd.size())
            break;
       try{
            c=o.play(this->brd);
            if (c.GetRow()>=brd.size()||c.GetColumn()>=brd.size()||this->brd[c]!='.'){
                throw std::string("Illegal Move");
                win=&x;
                return;
            }
       }
       catch(...){
            win=&x;
            return;
       }
      this->brd[c]='O';
      
      if(check(c)){
           win=&o;
           return;
       }
        count++;
    }
    win=&o;
}
bool TicTacToe:: check(Coordinate c){
    bool flag=true;
    for(uint i=0;i<brd.size();++i){
        if(brd[{c.GetRow(),i}]!=brd[{c.GetRow(),c.GetColumn()}]){
            flag =false;
            break;
        }
    }
    if(flag)
        return true;
    flag=true;
    for(uint i=0;i<brd.size();++i){
        if(brd[{i,c.GetColumn()}]!=brd[{c.GetRow(),c.GetColumn()}]){
            flag =false;
            break;
        }
    }
    if(flag)
        return true;
    flag=true;
    if(c.GetRow()==c.GetColumn()){
        for(uint i=0;i<brd.size();++i){
            if(brd[{i,i}]!=brd[{c.GetRow(),c.GetColumn()}]){
                flag=false;
                break;
            }
        }
        if(flag)
            return true;
        flag=true;
    }
    if(c.GetRow()==brd.size()-1-c.GetColumn()){
        for(uint i=0;i<brd.size();++i){
            if(brd[{i,brd.size()-1-i}]!=brd[{c.GetRow(),c.GetColumn()}]){
                flag=false;
                break;
            }
        }
        if(flag)
            return true;
    }
    return false;
}
const Player& TicTacToe:: winner() const{
    return *win;
}
