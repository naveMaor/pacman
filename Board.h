#pragma once
#include <iostream>
#include <string.h>
#include "Utilities.h"

//enum sizeEnum { WIDTH = 70, HIGHT = 20 };
enum sizeEnum { WIDTH = 80, HIGHT = 25 };

class Board
{
    unsigned char board[HIGHT][WIDTH] = {};
    
public:
	void const printBoard() const;
    // This function return the value in the board of request place, the x and y that requested are opposite in the board
    unsigned char getBoardValFromPoint(int x, int y)const { return board[y][x]; };
    void setBoardValByPoint(int x, int y) { board[y][x] = boardGarbageVal; }; // Set garabge value
    void setBoardLine(int hight, unsigned char* line);
    void printPreviousBoard() const;
    void resetBoard();
    bool breadcrumbleft() const;
    
};

