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
            cout << board[i][j];
        cout << endl;
    } 
};

/* This function print the previous board before pausing*/
void Board::printPreviousBoard() const
{
    for (int i = 0; i < boardHight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            if (board[i][j] == boardGarbageVal)
                cout << (char)space;
            else
                cout << board[i][j];
        }
        cout << endl;
    }
}

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
            board[hight][x] = w;
        else if (line[x] == '&')
            infoPosition = { x, hight };
        else if (line[x] == '%')
            board[hight][x] = ' ';
        else
        {
            board[hight][x] = bc;
            breadCrumbsCount++;

            if (line[x] == '$')
            {
                ghostStartingPositions[ghostCount] = { x, hight };
                ghostCount++;
            }
            else if (line[x] == '@')
                pacmanStartingPosition = { x, hight };
        }
    }      
}

void Board::initBoard() 
{
    int hight = infoPosition.getY() - 1;
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i==0 || i == 2)
            for (j = 0; j < 20; j++)
                board[hight][j] = w;
        else
        {
            for (j = 0; j < 20; j++)
                if(j == 0 || j == 19)
                    board[hight][j] = w;
                else
                    board[hight][j] = ' ';
        }
        hight++;
    }
}