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
}

void Board::initInfoPosition() 
{
    int hight = infoPosition.getY() - 1;
    int j = 0, x = infoPosition.getX();
    gotoxy(x, hight);
    for (int i = hight; i < hight + 3 && (hight + 3 < HIGHT) ; i++)
    {
        if (i == hight || i == hight + 2)
            for (j = x; (j < x + 20) && j < WIDTH; j++)
            {
                board[hight][j] = w;
                cout << board[hight][j];
            }
        else
        {
            for (j = x; (j < x + 20) && j < WIDTH; j++)
                if (j == x || j == x + 19)
                {
                    board[hight][j] = w;
                    cout << board[hight][j];
                }
                else
                {
                    board[hight][j] = ' ';
                    cout << " ";
                }
        }
        //hight++;
        gotoxy(infoPosition.getX(), i+1);
    }
    gotoxy(0,0);

}

Point Board:: getGhostStartingPosition(int index) const 
{
    return ghostStartingPositions[index]; 
}