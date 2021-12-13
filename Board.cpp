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
