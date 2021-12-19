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
    for (int i = 0; i < boardHight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            if ((board[i][j] == boardGarbageVal) || board[i][j] == gameInfoArea)
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


void Board:: setBoardLine(int hight, const char* line,int width)
{
    if(isGameInfoExist)
        while (board[hight][infoPosition.getX()] == gameInfoArea)
        {
            boardStartHight++;
            boardEndHight++;
            hight++;
        }
    for (int x = 0; x < width && x < WIDTH; x++)
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
        {
            isGameInfoExist = true;
            infoPosition = { x, hight };
            initInfoPosition();
        }
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
            {
                setPacmanExist(true);
                pacmanStartingPosition = { x, hight };
            }
        }
    } 
    isFirstWallInLine = true;
}

void Board::initInfoPosition() 
{
    int j = 0, x = infoPosition.getX(), y = infoPosition.getY();

    for (int i = y; i < y + 3 && (y + 3 < HIGHT); i++)
    {
        for (j = x; (j < x + 20) && j < WIDTH; j++)
        {
            if (board[i][j] == breadCrumb)
                breadCrumbsLeft--;
            board[i][j] = gameInfoArea;
        }
    }
}


void Board:: initBoardData(Point& gameInfo)
{
    initInfoPosition();
    gameInfo = infoPosition;
    printBoard();
}

void Board::resetBoardDataMembers()
{
    isFirstWallInLine = isFirstWall = true;
    breadCrumbsLeft = ghostCount = boardWidth = boardHight = boardStartHight = boardStartWidth = boardEndHight = 0;
}