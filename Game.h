#pragma once
#include <iostream>
#include <fstream>
#include "Board.h"
#include "Pacman.h"
#include "Board.h"
#include "Ghost.h"
#include "Utilities.h"
#include "Pacman.h"
#include "Point.h"
#include <string>
#include <stdio.h>
using namespace std;

class Game
{
private:
	enum initObjLocation {
		pacmanStartX = 1, pacmanStartY = 1,
		ghostOneStartX = 50, ghostOneStartY = 14,
		ghostTwoStartX = 10, ghostTwoStartY = 3
	};
	enum sleepEnum { shortPauseWindow = 2500, longPauseWindow = 4000, pacmanSpeed = 100 };
	int userChoice = 4;
	Ghost ghostOne = {ghostOneStartX,ghostOneStartY};
	Ghost ghostTwo = {ghostTwoStartX,ghostTwoStartY};
	Pacman player = {pacmanStartX,pacmanStartY};
	Board board;
	bool b_IsColorGame = true;

public:
	// Game functions
	int menu();
	void printGameMenu();
	void printGameSettings();
	void gameSettings();
	bool checkValidUserInput(int userChoice);
	void const printInstructions();
	void initGame(bool b_color);
	void initGameObj();
	void initGhosts();
	void playGame();
	void pauseGame();
	void const printPreviousGame();
	bool checkWin();
	void const winGame();
	void gameOver();
	void printLife();
	void resetPrintLife();
	void printScore();
	void printPlayerHitGhost();
	void removePrintPlayerHitGhost();
	void drawGameObj();
	void chooseColor();
	bool getIsColorGame() const { return b_IsColorGame; };
	void setIsColorGame(bool boolean) { b_IsColorGame = boolean; }
	void clearCenter();
	void resetGame();

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

