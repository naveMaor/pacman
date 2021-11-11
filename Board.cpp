// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Board.h"

void Board::buildBoard()
{
    char boardi[HIGHT][WIDTH] = {

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
    };
    std::cout << boardi;
}

//Board::Board() : map {
//     "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n",
//     "O             OO                                               OO              O\n",
//     "O             OO                                               OO              O\n",
//     "O   OOOOO     OO       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       OO      OOOOO   O\n",
//     "O   OOOOO     OO       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       OO      OOOOO   O\n",
//     "O   OO                                                                    OO   O\n",
//     "O   OO                                                                    OO   O\n",
//     "O   OO                                                                    OO   O\n",
//     "O   OO    OOOOOOO                                              OOOOOOO    OO   O\n",
//     "O         OOOOOOO                                              OOOOOOO         O\n",
//     "O                                                                              O\n",
//     "O         OOOOOOO      OOOOOOO         OO         OOOOOOO                      O\n",
//     "O         OOOOOOO      OOOOOOO         OO         OOOOOOO      OOOOOOO         O\n",
//     "O                      OO                              OO      OOOOOOO         O\n",
//     "O                      OO              OO              OO                      O\n",
//     "O         OOOOOOO      OO              OO              OO      OOOOOOO         O\n",
//     "O   OO    OOOOOOO      OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      OOOOOOO    OO   O\n",
//     "O   OO                                                                    OO   O\n",
//     "O   OO                                                                    OO   O\n",
//     "O   OO                                                                    OO   O\n",
//     "O   OOOOO     OO       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       OO      OOOOO   O\n",
//     "O   OOOOO     OO       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       OO      OOOOO   O\n",
//     "O             OO                                               OO              O\n",
//     "O             OO                                               OO              O\n",
//     "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n"
//    }
//{}   

void Board::printBoard()
{
    std::cout << map;
};

