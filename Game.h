#pragma once
#include <iostream>
#include <queue>
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


struct  QItem {
public:
	int row;
	int col;
	Point p;
	QItem(int x, int y,  Point p)
		: row(x), col(y), p(p)
	{
	}
};


class Game
{
private:
	enum initObjLocation {
		pacmanStartX = 1, pacmanStartY = 1,
		ghostOneStartX = 3, ghostOneStartY = 9,
		ghostTwoStartX = 14, ghostTwoStartY = 14
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
	void setGameSpeed(int gameSpeed) { gameSpeedVal = gameSpeed; }
	Point minDistance(Point GhostLocation, Point PlayerLocation);

	// Ghosts functions
	void initGameAfterGhostHit();
	bool ghostHit(Ghost ghost);
	bool ghostsHit();
	void removeGhosts();	
	void ghostsMove();
	void GhostchangeSmartPosition(Ghost& G);


	// Pacman functions
	void pacmanMove(Board &b);
	void getUserKeyboard();
	void removePacman();
	

	// Fruit functions
	void initFruit();
	void ghostHitFruit();
	void pacmanHitFruit();
	void unDisplayFruit();
	void fruitMove();
	void hideOrShowFruit();



	Point notfound(){
		Point p1(-1, -1);
		cout << "not found" << endl;
		return p1;
	}

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

