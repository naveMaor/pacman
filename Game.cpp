// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Game.h"

void Game::menu()
{
	cout << "Welcome to PacmanGame \n"
		"(1) Start a new game\n"
		"(8) Present instructions and keys\n"
		"(9) EXIT\n"
		"\nChoice: "<< endl;

	cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		break;

	case 8:
		break;

	case 9:
		break;

	}
}


bool Game::PacmanHitGhost(Ghost g1, Pacman player)
{

	Point Ppacman = player.getPacmanBody();
	Point Pghost = g1.getGhostBody();

	if (Ppacman.getX() == Pghost.getX() && Ppacman.getY() == Pghost.getY())
	{
		return true;
	}

	return false;
}

