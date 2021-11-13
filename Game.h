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
	Ghost ghostOne = {50,14};
	Ghost ghostTwo = {10,3};
	Pacman player = {1,1};
	Board board;

public:
	int menu();
	void printInstructions();
	void initGame();
	void playGame();
	void pauseGame();
	void printPreviousGame();
	void gameOver();
	void printLife();
	void printScore();


	// Ghosts functions
	bool ghostHit(Ghost ghost);
	bool ghostsHit();
	void ghostRandomMove(Ghost& ghost);
	void ghostIlustrateNextMove(int& x, int& y, int dir);
	bool ifLastGhostPositionWasBreadcrumb(int x, int y);
	void printBreadCrumbs(int x, int y);
	void initGameAfterGhostHit();
	void ghostsMove();
	bool checkGhostValidMove(int x, int y, int dir);
	void removeGhosts();
	void removeGhost(Ghost ghost);

	// Pacman functions
	void pacmanMove();
	void getUserKeyboard();
	void removePacman();

};

