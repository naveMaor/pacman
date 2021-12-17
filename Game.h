#ifndef GAME_H
#define GAME_H
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
#include "File.h"
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
	bool b_IsColorGame = true;
	int gameSpeedVal = mediumGameSpeed, maxScoreInCurrScreen, scoreOfAllWinnedScreens = 0;
	

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
	int getGameSpeedVal() const { return gameSpeedVal; }
	int getMaxScoreInCurrScreen() const{ return maxScoreInCurrScreen; }
	int getScoreOfAllWinnedScreens() const{ return scoreOfAllWinnedScreens; }

	void setIsColorGame(bool boolean) { b_IsColorGame = boolean; }
	void setGameSpeed(int gameSpeed) { gameSpeedVal = gameSpeed; }
	void setGameObjectsPositions();
	void setMaxScoreInCurrScreen(int score) { maxScoreInCurrScreen = score; }
	void setWinnedScore(int score) { scoreOfAllWinnedScreens += score; }
	void setGameObjectsColors();

	// Ghosts functions
	void initGameAfterGhostHit();
	bool ghostHit(Ghost ghost);
	bool ghostsHit();
	void removeGhosts();	
	void ghostsMove();


	// Pacman functions
	void pacmanMove(Board &b);
	void getUserKeyboard();
	void removePacman();
	

	// Fruit functions
	void initFruit();
	void ghostHitFruit();
	bool isGhostHitFruit();
	void pacmanHitFruit();
	void unDisplayFruit();
	void fruitMove();
	void hideOrShowFruit();



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


#endif