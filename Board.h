#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Board
{
    enum { WIDTH = 82, HIGHT = 25 };
    char map[HIGHT][WIDTH];

public:
    Board()
        : map({

            "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n",
            "O             OO                                               OO              O\n",
            "O             OO                                               OO              O\n",
            "O   OOOOO     OO       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       OO      OOOOO   O\n",
            "O   OOOOO     OO       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       OO      OOOOO   O\n",
            "O   OO                                                                    OO   O\n",
            "O   OO                                                                    OO   O\n",
            "O   OO                                                                    OO   O\n",
            "O   OO    OOOOOOO                                              OOOOOOO    OO   O\n",
            "O         OOOOOOO                                              OOOOOOO         O\n",
            "O                                                                              O\n",
            "O         OOOOOOO      OOOOOOO         OO         OOOOOOO                      O\n",
            "O         OOOOOOO      OOOOOOO         OO         OOOOOOO      OOOOOOO         O\n",
            "O                      OO                              OO      OOOOOOO         O\n",
            "O                      OO              OO              OO                      O\n",
            "O         OOOOOOO      OO              OO              OO      OOOOOOO         O\n",
            "O   OO    OOOOOOO      OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      OOOOOOO    OO   O\n",
            "O   OO                                                                    OO   O\n",
            "O   OO                                                                    OO   O\n",
            "O   OO                                                                    OO   O\n",
            "O   OOOOO     OO       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       OO      OOOOO   O\n",
            "O   OOOOO     OO       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       OO      OOOOO   O\n",
            "O             OO                                               OO              O\n",
            "O             OO                                               OO              O\n",
            "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n"
}) {};

	void buildBoard();
	void printBoard();
};

