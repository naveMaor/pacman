#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <queue>
//todo might delete late
#include "Menu.h"
#include "Board.h"
#include "Pacman.h"
#include "Board.h"
#include "Ghost.h"
#include "Utilities.h"
#include "Pacman.h"
#include "Point.h"
#include "Fruit.h"
#include "File.h"
#include <string>
#include <stdio.h>
#include "Print.h"

//todo might delete late
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




	//--------------


	/*Ghost ghostOne = {ghostOneStartX,ghostOneStartY};
	Ghost ghostTwo = {ghostTwoStartX,ghostTwoStartY };
	Pacman player = {pacmanStartX,pacmanStartY};
	Fruit fruit = {5,5};*/
	Ghost ghosts[4];
	int numOfGhosts;
	//Ghost ghostOne;
	//Ghost ghostTwo;
	Pacman player;
	Fruit fruit;
	Board board;
	Menu menu;
	Print print;
	bool b_IsColorGame = true;
	int gameSpeedVal = mediumGameSpeed, maxScoreInCurrScreen, scoreOfAllWinnedScreens = 0;
	

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

	// TODO: Delete next 4 function
	bool getIsColorGame() const { return b_IsColorGame; };
	int getGameSpeedVal() const { return gameSpeedVal; }
	int getMaxScoreInCurrScreen() const{ return maxScoreInCurrScreen; }
	int getScoreOfAllWinnedScreens() const{ return scoreOfAllWinnedScreens; }

	void setIsColorGame(bool boolean) { b_IsColorGame = boolean; }
	void setGameSpeed(int gameSpeed) { gameSpeedVal = gameSpeed; }
	void setGameObjectsPositions();
	void setMaxScoreInCurrScreen(int score) { maxScoreInCurrScreen = score; }
	void setWinnedScore(int score) { scoreOfAllWinnedScreens += score; }
	void setGameObjectsColors();

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








	
};


#endif