#pragma once
#include <iostream>
#include <string.h>
#include "Utilities.h"

using namespace std;

class Board
{
    enum sizeEnum { WIDTH = 70, HIGHT = 20};

    unsigned char board[HIGHT][WIDTH] = {
        {w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {' ',bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,' '},
        {' ',bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,' '},
        {w,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,w},
        {' ',bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,' '},
        {' ',bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,' '},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w}
    };
public:
	void const printBoard();
    unsigned char getBoardValFromPoint(int x, int y)const { return board[y][x]; };
    void setBoardValByPoint(int x, int y) { board[y][x] = 's'; }; // garabge value
    void printPreviousBoard();
};

