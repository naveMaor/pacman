#pragma once
#include "Board.h"
#include "Pacman.h"
#include "Board.h"
#include "Ghost.h"
#include "io_utils_.h"
#include "Pacman.h"
#include "Point.h"



class Game
{
private:
	int userChoice = 4;
	Ghost ghostOne = {10,15};
	Ghost ghostTwo = {30,15};
	Pacman player = {1,1};
	Board board;

	

public:
	int menu();
	void playGame(int userChoice);
	void initGame();
	// returns true if x and y values of Ghost and Pacman are equal.
	bool PacmanHitGhost(Ghost g1, Pacman player);
	void pacmanMove();
	void ghostRandomMove(Ghost ghost);
	bool checkGhostValidMove(int x, int y, int dir);
	void ghostNextMove(int& x, int& y, int dir);
	bool ifLastGhostPositionWasFood(int x, int y);
	

};

