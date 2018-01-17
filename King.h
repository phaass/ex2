//
// Created by phaass on 1/15/18.
//

#ifndef CPPEX2_KING_H
#define CPPEX2_KING_H


#include "Piece.h"

class King: public Piece
{
    virtual static int move(int x, int y, int new_x, int new_y, int currentPlayer, Board board);
    virtual static int isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board);
    virtual static int isCheckMate(int x, int y, int currentPlayer, Board board);
    virtual static int isCheck(int x, int y, int currentPlayer, Board board);

    virtual static int isThreat(int xRef, int yRef, int x, int y, int currentPlayer, Board board);


    int horseThreat(int x, int y, int currentPlayer, Board board);
};


#endif //CPPEX2_KING_H
