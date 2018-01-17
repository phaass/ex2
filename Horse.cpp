//
// Created by phaass on 1/15/18.
//

#include "Horse.h"




virtual static int Horse::move(int x, int y, int new_x, int new_y, int currentPlayer, Board board){
    if ((isPossibleMove(x, y, new_x, new_y, currentPlayer, board)) == 0)
    {

        board.movePiece(x,y,new_x,new_y);
        return 1;
    }

    return 0;
}


virtual static int Horse::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board){

    int yMove = new_y - y;
    int xMove = new_x - x;

    if((xMove == 1 && yMove == 2) && !board.isOutOfBoard(new_x,new_y) ){
        if ((board.isCellEmpty(new_x, new_y) == 1) | (board.getToolPlayer(new_x, new_y)) != currentPlayer){
            return 1;
        }

    }
}

