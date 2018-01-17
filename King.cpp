//
// Created by phaass on 1/15/18.
//

#include "King.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "Horse.h"


virtual static int King::move(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{
    if ((isPossibleMove(x, y, new_x, new_y, currentPlayer, board)) == 0)
    {
        board.movePiece(x, y, new_x, new_y);
        return 1;

    }

    return 0;
}

virtual static int King::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{
    int yMove = new_y - y;
    int xMove = new_x - x;
    //to add:first move can be two steps.



    if (((0 < xMove < 1) && (0 < yMove < 1)) && !board.isOutOfBoard(new_x, new_y)
        && !isCheck(new_x, new_y,currentPlayer, board))
    {
        if (board.getToolPlayer(new_x, new_y) != currentPlayer)
        {
            return 1;
        }
    }

    return 0;


}

virtual static int King::isCheckMate(int x, int y, int currentPlayer, Board board)
{
    return (isCheck(x,y,currentPlayer, board) && isCheck(x+1,y,currentPlayer, board)
            && isCheck(x-1,y,currentPlayer, board) && isCheck(x,y+1,currentPlayer, board)
            && isCheck(x,y-1,currentPlayer, board) && isCheck(x+1,y+1,currentPlayer, board)
            && isCheck(x-1,y-1,currentPlayer, board)) ? 1 : 0;
}

virtual static int King::isCheck(int x, int y, int currentPlayer, Board board)
{
    for (int i = 0; i <= 8; i++)
    {

        if (!board.isOutOfBoard(x, y + i))
        {
            if (isThreat(x, y, x, y + i, currentPlayer, board))
            {
                return 1;
            }
        }
        if (!board.isOutOfBoard(x, y + i))
        {
            if (isThreat(x, y, x, y - i, currentPlayer, board))
            {
                return 1;
            }
        }
        if (!board.isOutOfBoard(x + i, y))
        {
            if (isThreat(x, y, x + i, y, currentPlayer, board))
            {
                return 1;
            }
        }
        if (!board.isOutOfBoard(x - i, y))
        {
            if (isThreat(x, y, x - i, y, currentPlayer, board))
            {
                return 1;
            }
        }

        if (isThreat(x, y, x + i, y + i, currentPlayer, board))
        {
            return 1;
        }
        if (isThreat(x, y, x - i, y - i, currentPlayer, board))
        {
            return 1;
        }
        if (isThreat(x, y, x + i, y - i, currentPlayer, board))
        {
            return 1;
        }
        if (isThreat(x, y, x - i, y + i, currentPlayer, board))
        {
            return 1;
        }

    }


    return 0;
}
static int King::horseThreat(int x, int y, int currentPlayer, Board board){
    return (isThreat(x, y, x-2,y-1,currentPlayer, board) |isThreat(x, y, x+2,y+1,currentPlayer, board) |
            isThreat(x, y, x-2,y+1,currentPlayer, board) | isThreat(x, y, x+2,y-1,currentPlayer, board) |
            isThreat(x, y, x-1,y-2,currentPlayer, board) |isThreat(x, y, x-1,y+2,currentPlayer, board)|
            isThreat(x, y, x+1,y-2,currentPlayer, board)| isThreat(x, y, x+1,y+2, currentPlayer, board)) ? 1 : 0;
}

static int King::isThreat(int xRef, int yRef, int x, int y, int currentPlayer, Board board)
{
    int piece = board.getToolPlayer(x, y);

    switch (piece)
    {
        case pawn:
            if (Pawn::isPossibleMove(x, y, xRef, yRef, currentPlayer, board))
            {
                return 1;
            }
        case bishop:
            if (Bishop::isPossibleMove(x, y, xRef, yRef, currentPlayer, board))
            {
                return 1;
            }
        case rook:
            if (Rook::isPossibleMove(x, y, xRef, yRef, currentPlayer, board))
            {
                return 1;
            }
        case queen:
            if (Queen::isPossibleMove(x, y, xRef, yRef, currentPlayer, board))
            {
                return 1;
            }
        case horse:
            if (Horse::isPossibleMove(x, y, xRef, yRef, currentPlayer, board))
            {
                return 1;
            }
        case king:
            if (King::isPossibleMove(x, y, xRef, yRef, currentPlayer, board))
            {
                return 1;
            }
        default:
            break;
    }
    return 0;
}


