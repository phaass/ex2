//
// Created by evyatar shalev on 07/01/2018.
//

#include "Pawn.h"



    static int firstMove = 1;

int Pawn::move(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{

    if ((isPossibleMove(x, y, new_x, new_y, currentPlayer, board)) == 0)
    {

       board.movePiece(x,y,new_x,new_y);
        return 1;
    }

    return 0;
}

virtual static int Pawn::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, const Board board)
{
    if (board.isOutOfBoard(new_x,new_y))
    {

        //print error
        return 0;
    }
    int yMove = new_y - y;
    int xMove = new_x - x;
    //to add:first move can be two steps.



    if ((xMove == 0 && yMove == 1) | (xMove == 0 && yMove == 2 && firstMove == 1))
    {
        if ((board.isCellEmpty(new_x, new_y) == 1))
        {
            return 1;
        }
    }


    if (xMove == 1 && yMove == 1)
    {
        if ((board.getToolPlayer(new_x, new_y)) != currentPlayer)
        {
            return 1;
        }
    }


    return -1;


}

