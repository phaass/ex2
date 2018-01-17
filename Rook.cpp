//
// Created by phaass on 1/15/18.
//

#include <algorithm>
#include "Rook.h"


virtual static int Rook::move(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{
    if((isPossibleMove(x, y, new_x, new_y, currentPlayer, board)) == 0)
    {

        board.movePiece(x,y,new_x,new_y);
    }

    return 0;
}

virtual static int Rook::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{
    const int yMove = new_y - y;
    const int xMove = new_x - x;

    if ((xMove == 0 | yMove == 0) && !board.isOutOfBoard(new_x, new_y))
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
}