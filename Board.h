#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string.h>
#include "Utilities.h"
#include "Point.h"

enum sizeEnum { WIDTH = 80, HIGHT = 25 };

class Board
{
    unsigned char board[HIGHT][WIDTH] = {};
    int boardWidth, boardHight;
    int breadCrumbsCount = 0;
    Point pacmanStartingPosition;
    Point ghostStartingPositions[4];
    int ghostCount = 0;
    Point infoPosition;
    
public:
    Board();
	void const printBoard() const;
    // This function return the value in the board of request place, the x and y that requested are opposite in the board
    unsigned char getBoardValFromPoint(int x, int y)const { return board[y][x]; };
    void setBoardValByPoint(int x, int y) { board[y][x] = boardGarbageVal; }; // Set garabge value
    void setBoardLine(int hight, char* line, int width);
    void printPreviousBoard() const;
    void resetBoard();
    bool breadcrumbleft() const;
    void initBoard();
    int getBoardWidth() { return boardWidth; }
    int getBoardHight() { return boardHight; }
    void setBoardWidth(int width) { boardWidth = width; };
    void setBoardHight(int hight) { boardHight = hight; };
    int getNumOfGhosts() { return ghostCount; }
    Point getPacmanStartingPosition() { return pacmanStartingPosition; }
    Point getGhostStartingPosition(int index) { return ghostStartingPositions[index]; }
    Point getInfoPosition() { return infoPosition; }
    
};

#endif
