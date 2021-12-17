#ifndef MENU_H
#define MENU_H
#include "Utilities.h"
#include <string>
#include <stdio.h>
#include <iostream>
using std::vector;

class Menu
{
	int userChoice = 4;

public:
	int menu();
	char stringToChar(string& s)const;

	void printGameMenu()const;
	void printInstructions()const;
	void printPacmanSpeedOptions()const;
	void printColorMenu();
	void printGameSettings(bool getIsColorGame, int currentSpeed, int NumberofGhosts, string screenPath, vector<string> screenNames);
	void printIsColorGame(bool getIsColorGame) const;
	void printCurrentSpeedGame(int currentSpeed)const;
	void printScreenNames(vector<string> screenNames)const;

	bool checkValidUserInput(string userChoice)const;
	bool checkValidUserSettings(string input) const;
	bool checkValidSpeedSettingsInput(string input) const;
	bool checkValidScreenInput(string input) const;

	void handleGameMenuSpeedSettingsInput();
	void handleGameMenuSettingsInput(bool getIsColorGame, int currentSpeed, string screenPath, vector<string> screenNames);
	void handleChoseScreen(vector<string> screenNames);

	

	/// Changes
	void setUserChoice(int newUserChoice) { userChoice = newUserChoice; }
	int getUserChoice() const { return userChoice; }
};

#endif