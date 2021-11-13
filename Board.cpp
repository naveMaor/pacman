// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Board.h"

/* This function print the board*/
void Board::printBoard()
{  
    for (int i = 0; i < HIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
                cout << board[i][j];
        cout << endl;
    } 
};

void Board::printPreviousBoard()
{
    for (int i = 0; i < HIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (board[i][j] == 's')
                cout << ' ';
            else
                cout << board[i][j];
        }
        cout << endl;
    }
}


