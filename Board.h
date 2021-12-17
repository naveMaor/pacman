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
    int breadCrumbsLeft = 0;
    Point pacmanStartingPosition;
    Point ghostStartingPositions[4];
    int ghostCount = 0;
    Point infoPosition;
    
public:
    Board();
	void const printBoard() const;
    void printPreviousBoard() const;
    void resetBoard();
    void initBoard();

    // This function return the value in the board of request place, the x and y that requested are opposite in the board
    unsigned char getBoardValFromPoint(int x, int y)const { return board[y][x]; };
    unsigned char getBoardValFromPoint(Point point)const { return board[point.getY()][point.getX()]; };
    int getBoardWidth() const { return boardWidth; }
    int getBoardHight() const { return boardHight; }
    int getNumOfGhosts() const { return ghostCount; }
    int getBreadCrumbsLeft() const { return breadCrumbsLeft; }
    Point getPacmanStartingPosition() const { return pacmanStartingPosition; }
    Point getGhostStartingPosition(int index) const{ return ghostStartingPositions[index]; }
    Point getInfoPosition() const { return infoPosition; }

    void eatBreadCrumb() { breadCrumbsLeft--; }
    void setBoardValByPoint(int x, int y) { board[y][x] = boardGarbageVal; }; // Set garabge value
    void setBoardLine(int hight, char* line, int width);
    void setBoardWidth(int width) { boardWidth = width; };
    void setBoardHight(int hight) { boardHight = hight; };
    
};

#endif
