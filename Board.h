#pragma once
#include <iostream>
#include <string.h>
#include "Utilities.h"
#include "File.h"


enum sizeEnum { HIGHT = 20, WIDTH = 70  };

class Board
{
    unsigned char board[HIGHT][WIDTH] = {
        {w,w,w,w,w,w,w,w,w,w,space,space,space,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,space,space,space,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,space,space,space,w,w,w,w,w,w,w,w,w,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {space,bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,space},
        {space,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,space},
        {w,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,w},
        {space,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,space},
        {space,bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,w,w,w,w,w,w,bc,bc,bc,bc,bc,bc,space},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,bc,w},
        {w,w,w,w,w,w,w,w,w,w,space,space,space,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,space,space,space,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,space,space,space,w,w,w,w,w,w,w,w,w,w}
    };
public:
	void const printBoard() const;
    // This function return the value in the board of request place, the x and y that requested are opposite in the board
    unsigned char getBoardValFromPoint(int x, int y)const { return board[y][x]; };
    void setBoardValByPoint(int x, int y) { board[y][x] = boardGarbageVal; }; // Set garabge value
    void printPreviousBoard() const;
    void resetBoard();

    
};

