#include <iostream>
#include "Piece.h"
#include "Pawn.h"

//define parameters for understanding the code:

#define A  0
#define B  1
#define C  2
#define D  3
#define E  4
#define F  5
#define G  6
#define H  7


#define greenColor  42
#define blueColor   46
#define whiteTool   37
#define blackTool   30


#define soldier 0
#define rook 1
#define horse 2
#define bishop 3
#define king 4
#define queen 5
#define none 6

#define whiteMove 0
#define blackMove 1




int currentPlayer = whiteMove , isWiner = -1;
int newXY[3] = {0};


int infoTools[8][8][3] = {none};

std::string intToStr(int index);
std::string whiteName , blackName,  smallTurret = "O-o", bigTurret = "o-o-o" ;
int tempMoveXY[4] = {0};

Soldier _soldier;
Tool _turret;
Tool _horse;
Tool _runner;
Tool _king;
Tool _queen;



void initialization();
void getNames();
int getNewXY();
int printBord();
int makeMove();


int main()
{
    _soldier = Soldier();

//  Initializes the "infoTools":
    initialization();
    printBord();


//  Getting names
    getNames();


    while(isWiner == -1) {

//      Getting a move. As long as the move is not valid - prints an error and waits for a normal move:
//      If the move is legal - execute it and return 0
        while ((getNewXY() == -1) || (makeMove() == -1)) {
            std::cout << " \33[37;41millegal move\33[0m" << "\n";
        }


//      Prints the board
        printBord();

//      If the king dies, the player wins
        if (isWiner == 0) {

            std::cout << currentPlayer + " won!";
        }

    }



    Tool tg = Tool();

    int oldXY[] = {0,0};
    int newXY[] = {2,2};


    return 0;
}


/**
 * Receives information from the "infoTools" table, and then prints
 * the board. Uses a sting connection before sending to print.
 * Prints on the sides of the board numbers, and on the edges - letters
 * @return 0 for OK
 */
int printBord(){
    std::cout << "     "; // ---------------------------
    std::cout << "ABCDEFGH\n\n";
    std::string temp;
    for (int i = 0 ; i < 8 ; i++){

        std::cout << 8-i << " ";
        for (int j = 0 ; j < 8 ; j++){
            temp = "\33[";
            temp += std::to_string(infoTools[i][j][2]);
            temp += ";";
            temp += std::to_string(infoTools[i][j][1]);
            temp += "m";
            temp += intToStr(infoTools[i][j][0]);
            temp += "\33[0m";

            std::cout << temp;

        }
        std::cout << " " << 8-i << "\n";
//        std::cout << "\n";
    }

    std::cout << "\nABCDEFGH\n"; // ---------------------------
//    std::cout << "\nABCDEFGH";

    return 0;
}

/**
 * Gets a character that needs to be printed, and returns its "ASCII" code
 * @param index - a tool
 * @return "ASCII" code
 */
std::string intToStr(int index){
    switch (index){

        case 0:
            return "\u265F";
        case 1:
            return "\u265C";
        case 2:
            return "\u265E";
        case 3:
            return "\u265D";
        case 4:
            return "\u265A";
        case 5:
            return "\u265B";
        case 6:
            return " ";  // -----------------------------

        default:
            return " ";
    }
}


/**
 * Accepts user names
 */
void getNames()
{
    std::cout << "Enter white player name:\n";
    std::cin >> whiteName;

    std::cout << "Enter black player name:\n";
    std::cin >> blackName;
}


/**
 * Receives an input for the move, in the form of "A3B5",
 * and converts it to a point on the game board (like the matrix)
 * For example:
 *  "A3B5"  ---> [0,2,1,4]
 *
 *  And for the special moves:
 *  "o-o-o" ---> [-1,0,0,0]
 *  "O-o'   ---> [-2,0,0,0]
 *
 * @return 0 for ok, -1 for error
 */
int getNewXY() {
    std::string tempMove;

    if (currentPlayer == whiteMove)
    {
        std::cout << whiteName + ": Please enter your move:\n";
        std::cin >> tempMove;
    }
    else
    {
        std::cout << blackName + ": Please enter your move:\n";
        std::cin >> tempMove;
    }


    if (tempMove.length() == 4)
    {
        for (int i = 0; i < 4;)
        {
            if ((64 < tempMove[i]) && (tempMove[i] < 73))
            {
                tempMoveXY[i] = int(tempMove[i]) - 65;

                i++;
            }
            else
            {
                return -1;
            }


            if ((47 < tempMove[i]) && (tempMove[i] < 56))
            {
                tempMoveXY[i] = int(tempMove[i]) - 49;
                i++;
            }
            else
            {
                return -1;
            }
        }

    } else if ((tempMove.length() == 3)) {
        for (int i = 0; i < 4; i++) {
            if (tempMove[i] != smallTurret[i]) {
                return -1;
            }
        }
        tempMoveXY[0] = -1;

    } else if ((tempMove.length() == 5)) {
        for (int i = 0; i < 6; i++) {
            if (tempMove[i] != bigTurret[i]) {
                return -1;
            }
        }
        tempMoveXY[0] = -2;
    } else {
        return -1;
    }


//    for (int i = 0; i < 4; i++) {
//        std::cout << tempMoveXY[i] << "\n";
//    }

        return 0;
    }






/**
 *
 * @return
 */
    int makeMove() {
        int old_x = tempMoveXY[0];
        int old_y = tempMoveXY[1];
        int new_x = tempMoveXY[3];
        int new_y = tempMoveXY[4];


        int Tooltype = infoTools[old_x][old_y][2];

        switch (Tooltype){
            case soldier:

                return _soldier._move(old_x , old_y , new_x , new_y , currentPlayer, infoTools);
            case _turret:
//                return _turret::_move(old_x , old_y , new_x , new_y , &infoTools, currentPlayer);
//            case _runner:
//                return _runner::_move(old_x , old_y , new_x , new_y , &infoTools,currentPlayer);
//            case _king:
//                return _king::_move(old_x , old_y , new_x , new_y , &infoTools,currentPlayer);
//            case _queen:
//                return _queen::_move(old_x , old_y , new_x , new_y , &infoTools, currentPlayer);
        }




        return 0;
    }



//#include <iostream>
//
//void pri(int a[2][2][2])
//{
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 2; j++){
//            for (int m = 0; m < 2; m++){
//                std::cout << a[i][j][m] << "\n";
//            }
//        }
//    }
//}
//
//int main()
//{
//    int a[2][2][2];
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 2; j++){
//            for (int k = 0 ; k < 2 ; k++){
////                std::cout << i << "  " << j << "  "  << k << "\n";
//                a[i][j][k] = i+k+j;
//
//
////            for (int m = 0; m < 3; m++) {
////                std::cout << m << "\n";
////            }
////
//
//////                std::cout << a[i][j][m] << "\n";
//            }
//        }
//    }
//    pri(a);
//    return 0;
//}