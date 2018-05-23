#pragma once

#include "DummyPlayers.h"
class TicTacToe  {
  /*
  *Declarence of varible
  */ 
  private:
    Board brd;
    Player* win;
    bool check(Coordinate c);
   /*
   *Declarence on function
   */ 
    public:
        TicTacToe(int);
        void print();
        Board board() const;
        void play(Player&,Player&);
        const Player& winner() const;
};
