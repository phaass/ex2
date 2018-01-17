//
// Created by phaass on 1/15/18.
//

#include "Bishop.h"

virtual static int Bishop::move(int x, int y, int new_x, int new_y, int currentPlayer, Board board){
     if((isPossibleMove(x, y, new_x, new_y, currentPlayer, board)) == 0)
    {

        board.movePiece(x,y,new_x,new_y);
        return 1;
    }

    return 0;
}

virtual static int Bishop::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{


    int yMove = new_y - y;
    int xMove = new_x - x;

    if ((xMove == yMove) && !board.isOutOfBoard(new_x, new_y))
    {
        if ((board.getToolPlayer(new_x, new_y)) != currentPlayer)
        {
            for (int i = x; i < new_x; i++)
            {
                if ((board.isCellEmpty(i, i) == 1))
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
}