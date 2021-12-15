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
#include "Print.h"


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
	Print print;
	bool b_IsColorGame = true;
	int gameSpeedVal = mediumGameSpeed;
	int win = 1092;
	



public:
	// Game functions
	void playGame();
	void initGame(bool b_color);
	void gameSettings();
	void gameSpeed();
	void initGameObj();
	void printPreviousGame()const;
	bool checkWin()const;
	void drawGameObj()const;
	void resetGame();
	void chooseColor();
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
	

	// Fruit functions
	void checkPacmanHitFruit();

	// Print function
	void winGame();
	void gameOver();




	//void printLife()const;
	//void resetPrintLife() const;
	//void pauseGame() const;
	//void clearCenter()const;
	//void printPlayerHitGhost()const;
	//void printScore()const;
	//void removePrintPlayerHitGhost()const;



	
};

