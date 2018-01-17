//
// Created by phaass on 1/15/18.
//

#include "Queen.h"

virtual static int Queen::move(int x, int y, int new_x, int new_y, int currentPlayer, Board board){
    if((isPossibleMove(x, y, new_x, new_y, currentPlayer, board)) == 0)
    {

        board.movePiece(x,y,new_x,new_y);
        return 1;
    }

    return 0;
};

virtual static int Queen::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board){

    const int yMove = new_y - y;
    const int xMove = new_x - x;

    if ((xMove == 0 | yMove == 0 | xMove == yMove) && !board.isOutOfBoard(new_x, new_y))
    {
        if ((board.getToolPlayer(new_x, new_y)) != currentPlayer)
        {

            for (int i = x, j = y; i < new_x, j < new_y; i++, j++)
            {
                if ((board.isCellEmpty(i, j) == 1))
                {
                    continue;
                }
                else
                {
                    return 0;
                }

            }

        }
        return 1;
    }
    return 0;
};