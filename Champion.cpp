#include "Champion.h"
/**
*Strategy to win the other player
*/

const Coordinate Champion::play(const Board& board){
   uint i=0,j=0,size=board.size()-1;
   //check the corrner
     Coordinate c={size,j};
     if(board[c]=='.')
   return c;
       c={i,size};
     if(board[c]=='.')
   return c;

   c={i+1,size-1};
     if(board[c]=='.')
   return c;

   c={size-1,j+1};
     if(board[c]=='.')
   return c;
   //run on all the board
   for(i = 1; i <= size; i++){
          c={size,i};
         if(board[c]=='.')
             return c;
    }
   
    for(i = 0; i <= size; i++){
        for(j = 0; j <= size; j++){
            c={i,j};
             if(board[c]=='.')
             return c;
        }
    }
    
    return {0,0};
}
