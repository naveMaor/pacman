#ifndef MENU_H
#define MENU_H
#include "Utilities.h"

#include <string>
#include <stdio.h>
#include <iostream>



class Menu
{
	int userChoice = 4;

public:
	
	int menu();
	void printGameMenu()const;
	void printInstructions()const;
	void printPacmanSpeedOptions()const;
	void printColorMenu();
	char stringToChar(string& s)const;
	bool checkValidUserInput(string userChoice)const;
	bool checkValidUserSettings(string input) const;
	void handleGameMenuSpeedSettingsInput();
	bool checkValidSpeedSettingsInput(string input) const;
	
	
	



	/// Changes
	void setUserChoice(int newUserChoice) { userChoice = newUserChoice; }
	int getUserChoice() const { return userChoice; }
};

#endif