#include "Board.h"

/* This function print the board*/
void const Board::printBoard() const
{  
    for (int i = 0; i < HIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)       
            cout << board[i][j];
        cout << endl;
    } 
};

/* This function print the previous board before pausing*/
void Board::printPreviousBoard() const
{
    for (int i = 0; i < HIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
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
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (board[i][j] == boardGarbageVal)
                board[i][j] = bc;
        }
    }
}


bool Board::breadcrumbleft() const
{
    for (int i = 0; i < HIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (board[i][j] == bc)
                return true;
        }
    }
}


void Board:: setBoardLine(int hight, char* line,int width)
{
    for (int x = 0; x < width; x++)
    {
       
        if (line[x] == '#')
            board[hight][x] = w;
        else if (line[x] == '@')
            pacmanStartingPosition = { x, hight };
        else if (line[x] == '$')
        {
            ghostStartingPositions[ghostCount] = { x, hight };
            ghostCount++;
        }
        else if (line[x] == '&')
            infoPosition = { x, hight };
        else
        {
            board[hight][x] = bc;
            breadCrumbsCount++;
        }
    }      
}

void Board::initBoard() 
{
    int hight = infoPosition.getY();
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i==0 || i == 2)
            for (j = 0; j < 20; j++)
                board[hight][j] = w;
        else
        {
            for (j = 0; j < 20; j++)
                if(j == 0 || j== 20)
                    board[hight][j] = w;
                else
                    board[hight][j] = ' ';
        }
    }
}