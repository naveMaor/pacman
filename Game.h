#pragma once
#include "Board.h"
#include "Pacman.h"
#include "Board.h"
#include "Ghost.h"
#include "io_utils_.h"
#include "Pacman.h"
#include "Point.h"
#include "Game.h"


class Game
{
private:
	int userChoice;
	Ghost ghostArr[2];
	/*Pacman player(int x,int y);*/
	

public:
	Game();
	void menu();
	// returns true if x and y values of Ghost and Pacman are equal.
	bool PacmanHitGhost(Ghost g1, Pacman player);

};

