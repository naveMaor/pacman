#pragma once
#include <iostream>
#include "Board.h"
#include "Pacman.h"
#include "Board.h"
#include "Ghost.h"
#include "Utilities.h"
#include "Pacman.h"
#include "Point.h"
#include "Fruit.h"
#include <string>
#include <stdio.h>

class Game
{
private:
	enum initObjLocation {
		pacmanStartX = 1, pacmanStartY = 1,
		ghostOneStartX = 50, ghostOneStartY = 14,
		ghostTwoStartX = 10, ghostTwoStartY = 3
	};
	enum sleepEnum { shortPauseWindow = 2500, longPauseWindow = 4000};
	enum gameSpeed { easyGameSpeed = 600, mediumGameSpeed = 300 , hardGameSpeed = 140, expertGameSpeed = 70};

	//------------------
	int Width, Hight;
	//------------------

	int userChoice = 4;
	int gameSpeedVal = mediumGameSpeed;
	Ghost ghostOne = {ghostOneStartX,ghostOneStartY};
	Ghost ghostTwo = {ghostTwoStartX,ghostTwoStartY};
	Pacman player = {pacmanStartX,pacmanStartY};
	Fruit fruit;
	Board board;
	bool b_IsColorGame = true;

public:
	// Game functions
	int menu();
	void printGameMenu()const;
	void printGameSettings()const;
	void gameSettings();
	void gameSpeed();
	bool checkValidUserInput(string userChoice)const;
	void printInstructions()const;
	void initGame(bool b_color);
	void initGameObj();
	void initGhosts();
	void playGame();
	void pauseGame();
	void printPreviousGame()const;
	bool checkWin()const;
	void winGame();
	void gameOver();
	void printLife()const;
	void resetPrintLife() const;
	void printScore()const;
	void printPlayerHitGhost()const;
	void removePrintPlayerHitGhost()const;
	void drawGameObj()const;
	void chooseColor();
	bool getIsColorGame() const { return b_IsColorGame; };
	void setIsColorGame(bool boolean) { b_IsColorGame = boolean; }
	void clearCenter()const;
	void resetGame();
	bool checkValidUserSettings(string input) const;
	void handleGameMenuSettingsInput();
	void handleGameMenuSpeedSettingsInput();
	bool checkValidSpeedSettingsInput(string input) const;
	void printPacmanSpeedOptions()const;
	void printIsColorGame() const;
	void printCurrentSpeedGame()const;
	int getGameSpeedVal() const { return gameSpeedVal; }
	void setGameSpeed(int gameSpeed) { gameSpeedVal = gameSpeed; }
	char stringToChar(string& s)const;

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
	

	// Fruit functions
	void initFruit();
	bool ghostHitFruit();
	bool pacmanHitFruit();
	void unDisplayFruit();
	void fruitMove();
	
};

