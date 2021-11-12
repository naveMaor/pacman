// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Game.h"


int main()
{
	Game newGame;
	int userChoice = newGame.menu();
	newGame.playGame(userChoice);



	
	return 0;
}