#include "Board.h"

Board::Board()
{
    for (int i = 0; i < HIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            board[i][j] = ' ';
}

/* This function print the board
   The first boardHight is zero so we print includ the board hight*/
void const Board::printBoard() const
{  
    for (int i = 0; i <= boardHight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            if ((board[i][j] == boardGarbageVal) || (board[i][j] == gameInfoArea) || (board[i][j] == cleanGameArea))
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
    bool isFirstWallInLine = true;

    int x = 0;
    if (isGameInfoExist)
        adjustBoardLineType(hight, x);

    for (x; x < width && x < WIDTH; x++)
    {
        board[hight][x] = line[x];
        
        if (line[x] == '#')
            handleWall(hight, x, isFirstWallInLine);

        else if (line[x] == '&')
            handleGameInfo(hight, x);

        else if (line[x] == '%')
            handleCleanGameArea(hight, x);

        else
        {
            if (board[hight][x] != gameInfoArea)
            {
                board[hight][x] = breadCrumb;
                breadCrumbsLeft++;
            }

            if (line[x] == '$')
                handleGhost(hight, x);
            else if (line[x] == '@')
                handlePacman(hight, x);
        }   
        if (board[hight][x] != gameInfoArea)
        {
            // Getting the first gameobject that is not gameInfoArea and this is the first valid board line
            if (!isStartHightSet)
            {
                boardStartHight = hight;
                isStartHightSet = true;
            }
            // Getting the last gameobject that is not gameInfoArea and this is the last valid board line
            boardEndHight = hight;
        }    
    } 
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
    isStartHightSet = false;
    breadCrumbsLeft = ghostCount = boardWidth = boardHight = boardStartHight = boardEndHight = 0;
    boardStartWidth = 80;
    infoPosition = { -1, -1 };
    pacmanStartingPosition = infoPosition = { -1, -1 };
    for(int i = 0; i < ghostCount; i++)
        ghostStartingPositions[i] = { -1, -1 };
}

/* This function handle getting wall in file*/
void Board::handleWall(int hight, int x, bool& isFirstWallInLine)
{
    board[hight][x] = wall;

    // Handle case the screen doesn't start from the most left (x = 0)
    if (isFirstWallInLine == true)
    {
        isFirstWallInLine = false;
        if (boardStartWidth > x)
            boardStartWidth = x;
    }
}

/* This function handle getting ghost in file*/
void Board::handleGhost(int hight, int x)
{
    if (ghostCount <= 4)
    {
        ghostStartingPositions[ghostCount].setX(x);
        ghostStartingPositions[ghostCount].setY(hight);
        ghostCount++;
    }
    else
        cout << "Two many ghosts in there board";
}

/* This function handle getting pacman in file*/
void Board::handlePacman(int hight, int x)
{
    if (!isPacmanExist) // take only first appear of pacman in board  
    {
        isPacmanExist = true;
        pacmanStartingPosition = { x, hight };
    }
}

/* This function handle getting game info in file - & */
void Board::handleGameInfo(int hight, int x)
{
    if (!isGameInfoExist)
    {
        isGameInfoExist = true;
        infoPosition = { x, hight };
        initInfoPosition();
    }
    else // if already game info set print breadcrum instead
        board[hight][x] = breadCrumb;
}

/* This function handle getting clean area in file - % */
void Board::handleCleanGameArea(int hight, int x)
{
    if(board[hight][x] != gameInfoArea)
        board[hight][x] = cleanGameArea;
}

/* This function adjust board line type when is this is the gameinfo area and there are more chars to init*/
void Board::adjustBoardLineType(int& hight, int &x)
{
    while (board[hight][x] == gameInfoArea)
        x++;
}

/* This function check if this is the game info area*/
bool Board:: isInGameInfoArea(Point point)
{
    if (getBoardValFromPoint(point) == gameInfoArea)
        return true;
    return false;
}
