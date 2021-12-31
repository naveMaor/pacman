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
#include <string>
#include <stdio.h>
#include "Fruit.h"
#include "NoviceGhost.h"
#include "GoodGhost.h"
#include "BestGhost.h"

class Game
{
private:
	string currScreenGame;
	vector<string> screensNames = File::getScreensName(screenPath);
	Ghost* ghosts[4]{};
	Pacman player;
	Fruit fruit;
	Board board;
	Menu menu;
	Print print;
	Point gameInfo;
	bool b_IsColorGame = true, singleGame = false, continueGame = true;
	int gameSpeedVal = mediumGameSpeed, numOfGhosts, GhostsLevel = Hard;
	
public:
	// Game functions
	void playGame(bool isSingleGame, string screenName);
	void playSingleGame();
	void initGame(bool b_color);
	void gameSettings();
	void gameSpeed();
	void initGameObj();
	void printPreviousGame()const;
	bool checkWin()const;
	void drawGameObj()const;
	void resetGame();
	void chooseColor();
	string choseScreen();
	void gameGhostsLevel();
	void pushdirectionsForObjects();
	void writesteps();

	// TODO: Delete next 4 function
	bool getIsColorGame() const { return b_IsColorGame; };
	int getGameSpeedVal() const { return gameSpeedVal; }
	vector<string> getScreenNames() const { return screensNames; }

	void setIsColorGame(bool boolean) { b_IsColorGame = boolean; }
	void setGameSpeed(int gameSpeed) { gameSpeedVal = gameSpeed; }
	void setGameObjectsPositions();
	void setGameObjectsColors();

	// Ghosts functions
	void initGameAfterGhostHit();
	bool ghostsHit(Point Body);
	void checkGhostsHit(Point Body);
	void removeGhosts();	
	void ghostsMove(int& countMoves, Point PlayerLocation);
	bool checkGhostCollision(Ghost& g1, Ghost& g2);

	// Pacman functions
	void pacmanMove(Board& b, int& countMoves);
	void getUserKeyboard();
	

	// Fruit functions
	void checkPacmanHitFruit();

	// Print function
	void winGame();
	void gameOver();
	void pauseGame();
	void exitGame();
};

#endif