#pragma once
#include <iostream>
#include <string.h>
#include "io_utils_.h"

using namespace std;

class Board
{
    enum { WIDTH = 70, HIGHT = 20};
    unsigned char w = 219, bc = 250;
    unsigned char board[HIGHT][WIDTH] = {
        {w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,' ',' ',' ',w,w,w,w,w,w,w,w,w,w},
        {w,' ',bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
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
	void printBoard();
    unsigned char getBoardValFromPoint(int x, int y)const { return board[x][y]; };
    void setBoardValByPoint(int x, int y) { board[x][y] = 's'; }; // garabge value
};

