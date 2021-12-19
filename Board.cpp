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

/* This function get the line from the board*/
void Board:: setBoardLine(int hight, const char* line,int width)
{
    if (isGameInfoExist)
        adjustBoardLineType(hight);

    for (int x = 0; x < width && x < WIDTH; x++)
    {
        if (line[x] == '#')
            handleWall(hight, x);

        else if (line[x] == '&')
            handleGameInfo(hight, x);
        else if (line[x] == '%')
            board[hight][x] = ' ';
        else
        {
            board[hight][x] = breadCrumb;
            breadCrumbsLeft++;            

            if (line[x] == '$')
                handleGhost(hight, x);
            else if (line[x] == '@')
                handlePacman(hight, x);
        }
    } 
    isFirstWallInLine = true;
}

/* This function init the game info area in the board*/
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

/* This function init board data*/
void Board:: initBoardData(Point& gameInfo)
{
    initInfoPosition();
    gameInfo = infoPosition;
    printBoard();
}

/* This function reset board data member after new game*/
void Board::resetBoardDataMembers()
{
    isPacmanExist = isGameInfoExist = false;
    isFirstWallInLine = isFirstWall = true;
    breadCrumbsLeft = ghostCount = boardWidth = boardHight = boardStartHight = boardStartWidth = boardEndHight = 0;
}

/* This function handle getting wall in file*/
void Board::handleWall(int hight, int x)
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

/* This function handle getting ghost in file*/
void Board::handleGhost(int hight, int x)
{
    if (ghostCount <= 4)
    {
        ghostStartingPositions[ghostCount] = { x, hight };
        ghostCount++;
    }
    else
        cout << "Two many ghosts in there board";
}

/* This function handle getting pacman in file*/
void Board::handlePacman(int hight, int x)
{
    if (!isPacmanExist)
    {
        isPacmanExist = true;
        pacmanStartingPosition = { x, hight };
    }
}

/* This function handle getting game info in file*/
void Board::handleGameInfo(int hight, int x)
{
    if (!isGameInfoExist)
    {
        isGameInfoExist = true;
        infoPosition = { x, hight };
        initInfoPosition();
    }
    else
        board[hight][x] = breadCrumb;
}

void Board::adjustBoardLineType(int& hight)
{
    while (board[hight][infoPosition.getX()] == gameInfoArea)
    {
        boardStartHight++;
        boardEndHight++;
        hight++;
    }
}