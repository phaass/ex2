//
// Created by phaass on 1/15/18.
//

#ifndef CPPEX2_ROOK_H
#define CPPEX2_ROOK_H


#include "Piece.h"

class Rook: public Piece
{
public:
    virtual static int move(int x, int y, int new_x, int new_y, int currentPlayer, Board board);

    virtual static int isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board);
};


#endif //CPPEX2_ROOK_H
