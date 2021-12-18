#include "Board.h"

Board::Board()
{
    for (int i = 0; i < HIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            board[i][j] = ' ';
}

/* This function print the board*/
void const Board::printBoard() const
{  
    for (int i = 0; i <= boardHight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            if (board[i][j] == boardGarbageVal || board[i][j] == gameInfoArea)
                cout << (char)space;
            else
                cout << board[i][j];
        }
        cout << endl;
    } 
};


/* This function reset the board to the begining*/
void Board::resetBoard()
{
    for (int i = 0; i < HIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
                board[i][j] = ' ';
}


void Board:: setBoardLine(int hight, char* line,int width)
{
    for (int x = 0; x < width; x++)
    {
        if (line[x] == '#')
        {
            board[hight][x] = wall;
            if (isFirstWall == true)
            {
                boardStartHight = hight;
                boardStartWidth = x;
                isFirstWall = false;
            }
            if (isFirstWallInLine == true)
            {
                isFirstWallInLine = false;
                boardEndHight++;
            }
        }
        else if (line[x] == '&')
            infoPosition = { x, hight };
        else if (line[x] == '%')
            board[hight][x] = ' ';
        else
        {
            board[hight][x] = breadCrumb;
            breadCrumbsLeft++;            

            if (line[x] == '$')
            {
                ghostStartingPositions[ghostCount] = { x, hight };
                ghostCount++;
            }
            else if (line[x] == '@')
                pacmanStartingPosition = { x, hight };
        }
    } 
    isFirstWallInLine = true;
}

void Board::initInfoPosition() 
{
    int hight = infoPosition.getY() - 1;
    int j = 0, x = infoPosition.getX();

    for (int i = hight; i < hight + 3 && (hight + 3 < HIGHT); i++)
        for (j = x; (j < x + 20) && j < WIDTH; j++)
            board[hight][j] = gameInfoArea;
}

Point Board:: getGhostStartingPosition(int index) const 
{
    return ghostStartingPositions[index]; 
}

void Board:: initBoardData(int& Hight, int& Width, Point& gameInfo)
{

    Hight = boardHight;
    Width = boardWidth;
    initInfoPosition();
    gameInfo = infoPosition;
    gameInfo.setX(gameInfo.getX() + 1);
    printBoard();
}