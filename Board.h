#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string.h>
#include "Utilities.h"
#include "Point.h"

enum sizeEnum { WIDTH = 80, HIGHT = 25 };

class Board
{
    bool isStartHightSet = false;
    unsigned char board[HIGHT][WIDTH] = {};
    int boardWidth = 0, boardHight = 0, boardStartHight = 0, boardStartWidth = 80, boardEndHight = 0;
    int breadCrumbsLeft = 0, ghostCount = 0;;
    Point pacmanStartingPosition;
    Point ghostStartingPositions[4] = {};
    Point infoPosition;

protected:
    bool isPacmanExist = false, isGameInfoExist = false;
  
public:
    Board();
	void const printBoard() const;
    void resetBoard();
    void initBoardData(Point& gameInfo);
    void initInfoPosition();
    void resetBoardDataMembers();

    // This function return the value in the board of request place, the x and y that requested are opposite in the board
    unsigned char getBoardValFromPoint(int x, int y)const { return board[y][x]; };
    unsigned char getBoardValFromPoint(Point point)const { return board[point.getY()][point.getX()]; };
    int getBoardWidth() const { return boardWidth; }
    int getBoardStartWidth() const { return boardStartWidth; }
    int getBoardHight() const { return boardHight; } // first hight is zero
    int getBoardStartHight() const { return boardStartHight; }
    int getBoardEndHight() const { return boardEndHight; }
    int getNumOfGhosts() const { return ghostCount; }
    int getBreadCrumbsLeft() const { return breadCrumbsLeft; }
    Point getPacmanStartingPosition() const { return pacmanStartingPosition; }
    Point getGhostStartingPosition(int index) const { return ghostStartingPositions[index]; }
    Point getInfoPosition() const { return infoPosition; }
    bool isInGameInfoArea(Point point);

    void eatBreadCrumb() { breadCrumbsLeft--; }
    void setBoardValByPoint(int x, int y) { board[y][x] = boardGarbageVal; }; // Set garabge value
    void setBoardLine(int hight, const char* line, int width);
    void setBoardWidth(int width) { boardWidth = width; };
    void setBoardHight(int hight) { boardHight = hight; }; // first hight is zero
    void setPacmanExist(bool isExist) { isPacmanExist = isExist; }
  
    void handleWall(int hight, int x, bool& isFirstWallInLine);
    void handleGhost(int hight, int x);
    void handlePacman(int hight, int x);
    void handleGameInfo(int hight, int x);
    void handleCleanGameArea(int hight, int x);
    void adjustBoardLineType(int& hight, int& x);
};
#endif
