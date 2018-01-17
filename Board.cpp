//
// Created by phaass on 1/14/18.
//

#include "Board.h"
#include "Piece.h"
#include "Pawn.h"

int infoTools, check;

Board::Board(int board)
{
    infoTools = board;
    check = 0;
}
Board::Board

/**
 * Initializing a game board by filling in the "infoTools" table
 */
void Board::initialization() {
//  Fills information about the color of the board
// (green or blue) and the color of the player in
//  each slot (white or black)
    int k = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (k % 2 == 0) {
                infoTools[i][j][2] = greenColor;
                infoTools[i][j][0] = none;
            } else {
                infoTools[i][j][2] = blueColor;
                infoTools[i][j][0] = none;
            }
            k++;
        }
        k++;
    }

    infoTools[0][0][0] = rook;
    infoTools[0][1][0] = horse;
    infoTools[0][2][0] = bishop;
    infoTools[0][3][0] = king;
    infoTools[0][4][0] = queen;
    infoTools[0][5][0] = bishop;
    infoTools[0][6][0] = horse;
    infoTools[0][7][0] = rook;


    infoTools[1][0][0] = pawn;
    infoTools[1][1][0] = pawn;
    infoTools[1][2][0] = pawn;
    infoTools[1][3][0] = pawn;
    infoTools[1][4][0] = pawn;
    infoTools[1][5][0] = pawn;
    infoTools[1][6][0] = pawn;
    infoTools[1][7][0] = pawn;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            infoTools[j][i][1] = blackTool;
        }
    }


    infoTools[7][0][0] = rook;
    infoTools[7][1][0] = horse;
    infoTools[7][2][0] = bishop;
    infoTools[7][3][0] = king;
    infoTools[7][4][0] = queen;
    infoTools[7][5][0] = bishop;
    infoTools[7][6][0] = horse;
    infoTools[7][7][0] = rook;


    infoTools[6][0][0] = pawn;
    infoTools[6][1][0] = pawn;
    infoTools[6][2][0] = pawn;
    infoTools[6][3][0] = pawn;
    infoTools[6][4][0] = pawn;
    infoTools[6][5][0] = pawn;
    infoTools[6][6][0] = pawn;
    infoTools[6][7][0] = pawn;

    for (int i = 0; i < 8; i++) {
        for (int j = 6; j < 8; j++) {
            infoTools[j][i][1] = whiteTool;
        }
    }
}

const int Board::isCellEmpty(int x, int y) const
{
    return infoTools[x][y][0] == none ? 1 : 0;
}
const int Board::getToolPlayer(int x, int y) const
{

    return infoTools[x][y][1];
}

const int Board::getColorPlayer(int x, int y) const{
    return infoTools[x][y][2];
}
void Board::movePiece(int x, int y, int new_x, int new_y){
    int toolType = infoTools[x][y][0];
    int toolColor = infoTools[x][y][1];
    infoTools[x][y][0] = none;
    infoTools[x][y][1] = none;
    infoTools[new_x][new_y][0] = toolType;
    infoTools[new_x][new_y][1] = toolColor;
}

const int Board::isOutOfBoard(int x, int y) const{
    if(x > 8 |y > 8){
        return 1;
    }
    return 0;
}