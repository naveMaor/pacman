#pragma once
#include <iostream>
#include "Menu.h"
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

	//------------------
	int Width, Hight;
	//------------------


	/* Menu Changes*/
	//int userChoice = 4;



	//--------------


	Ghost ghostOne = {ghostOneStartX,ghostOneStartY};
	Ghost ghostTwo = {ghostTwoStartX,ghostTwoStartY };
	Pacman player = {pacmanStartX,pacmanStartY};
	Fruit fruit = {5,5};
	Board board;
	Menu menu;
	bool b_IsColorGame = true;
	int gameSpeedVal = mediumGameSpeed;



public:
	// Game functions
	void playGame();
	void initGame(bool b_color);
	void gameSettings();
	void printPlayerHitGhost()const;
	void printGameSettings() const;
	void printIsColorGame() const;
	void handleGameMenuSettingsInput();
	void printCurrentSpeedGame()const;
	void gameSpeed();
	void initGameObj();
	void pauseGame();
	void printPreviousGame()const;
	bool checkWin()const;
	void winGame();
	void gameOver();
	void printLife()const;
	void resetPrintLife() const;
	void printScore()const;
	void removePrintPlayerHitGhost()const;
	void drawGameObj()const;
	void clearCenter()const;
	void resetGame();
	void chooseColor();
	bool getIsColorGame() const { return b_IsColorGame; };
	void setIsColorGame(bool boolean) { b_IsColorGame = boolean; }
	int getGameSpeedVal() const { return gameSpeedVal; }
	bool checkValidMove(int x, int y, int dir);
	void IlustrateNextMove(int& x, int& y, int dir);
	void RandomMove(Ghost& ghost);
	void setGameSpeed(int gameSpeed) { gameSpeedVal = gameSpeed; }
	bool ifLastPositionWasBreadcrumb(int x, int y);

	// Ghosts functions
	void initGameAfterGhostHit();
	bool ghostHit(Ghost ghost);
	bool ghostsHit();
	void printBreadCrumbs(int x, int y);
	void ghostsMove();
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



	//------------------------------------
	// Thos functions move to menu class 
	// 
	//
	//int menu();
	//void printGameMenu()const;
	//void printPacmanSpeedOptions()const;
	//void printInstructions()const;
	//bool checkValidUserInput(string userChoice)const;
//	char stringToChar(string& s)const;
//	bool checkValidUserSettings(string input) const;
	//void handleGameMenuSpeedSettingsInput();
	//bool checkValidSpeedSettingsInput(string input) const;
	
};

