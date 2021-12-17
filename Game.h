#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Point.h"
#include "Print.h"
#include "File.h"
#include "Fruit.h"
#include "Utilities.h"
#include <string>
#include <stdio.h>




class Game
{
private:
	int Width, Hight;
	vector<string> screensNames = File::getScreensName(PATH);
	Ghost* ghosts[4]{};
	int numOfGhosts;
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
	void gameGhosts();
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
	void setMaxScoreInCurrScreen(int score) { maxScoreInCurrScreen = score; }
	void setWinnedScore(int score) { scoreOfAllWinnedScreens += score; }
	void setGameObjectsPositions();
	void setGameObjectsColors();

	// Ghosts functions
	void initGameAfterGhostHit();
	bool ghostHit(Ghost ghost);
	bool ghostsHit(Point Body);
	void removeGhosts();	
	void ghostsMove();
	void GhostchangeSmartPosition(Ghost& G);


	// Pacman functions
	void pacmanMove(Board& b, int& countMoves);
	void getUserKeyboard();
	

	// Fruit functions
	void checkPacmanHitFruit();

	// Print function
	void winGame();
	void gameOver();

};


#endif