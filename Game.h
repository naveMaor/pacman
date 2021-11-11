#pragma once
#include "Board.h"
#include "Ghost.h"
#include "io_utils_.h"
#include "Pacman.h"
#include "Point_.h"





class Game
{
private:
	//Ghost g1;
	//Pacman player;


public:
	// returns true if x and y values of Ghost and Pacman are equal.
	bool PacmanHitGhost(Ghost g1, Pacman player);

};

