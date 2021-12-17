#include "Menu.h"



/* This function get user choice of menu*/
int Menu::menu()
{
	printGameMenu();
	string input;
	getline(cin, input);

	/* If the user enter invalid option clear and ignore cin input */
	while (!checkValidUserInput(input))
	{
		clearScreen();
		cout << "You enterd incorrect option, please choose again.\n\n";
		printGameMenu();
		getline(cin, input);
	}
	userChoice = stoi(input);

	return userChoice;
}

void Menu::printGameMenu() const
{
	cout << "Welcome to PacmanGame \n"
		"(1) Start a new game\n"
		"(2) Game settings\n"
		"(8) Present instructions and keys\n"
		"(9) EXIT\n";
}


/* This function print pacman instructions*/
void Menu::printInstructions() const
{
	clearScreen();
	cout << "Pacman game instructions:\n"
		"The purpose of the game is to eat all the breadcrumbs (dots).\n"
		"If pacman makes contact with a ghost, he will lose a life.\n"
		"The game ends when all lives are lost.\n\n"
		"The keys:\n"
		"Up- 'w' or 'W'\n"
		"Down- 'x' or 'X'\n"
		"Left- 'a' or 'A'\n"
		"Right- 'd' or 'D'\n"
		"Stay- 's' or 'S'\n"
		"Pause/continue the game- ESC\n\n"
		"Press any key to return the menu\n";

	char c = _getch();
	clearScreen();
}

/* This function prints the pacman speed settings options*/
void Menu::printPacmanSpeedOptions() const
{
	setTextColor(Color::WHITE);
	cout << "Please enter pacman speed\n"
		"1. Easy\n"
		"2. Medium\n"
		"3. Hard\n"
		"4. Expert\n\n"
		"Choice: ";
}

/* This function prints the pacman speed settings options*/
void Menu::printPacmanGhostsOptions() const
{
	setTextColor(Color::WHITE);
	cout << "Please choose number of ghosts\n"
		"1. One\n"
		"2. Two\n"
		"3. Three\n"
		"4. Four\n\n"
		"Choice: ";
}


void Menu::printColorMenu()
{
	cout << "Do you want to use colors in the game?" << endl;
	cout << "Press Y for yes or N for no" << endl;
}


/* Check if user input is correct*/
bool Menu::checkValidUserInput(string input) const
{
	if (input.length() == 1)
	{
		char chUser = stringToChar(input);
		if (chUser >= '0' && chUser <= '9')
			if ((chUser == '1') || (chUser == '2') || (chUser == '8') || (chUser == '9'))
				return true;
	}
	return false;
}

/* This function change string to char*/
char Menu::stringToChar(string& s) const
{
	char res = s[0];
	return res;
}


/* This function check valid user input*/
bool Menu::checkValidUserSettings(string input) const
{
	if (input.length() == 1 && userChoice != 0)
	{
		int userChoice = stoi(input);
		if ((userChoice == 1) || (userChoice == 2) || (userChoice == 3) || (userChoice == 4))
			return true;
	}
	return false;
}


/* This function handle game menu speed settings input*/
void Menu::handleGameMenuSpeedSettingsInput()
{
	string input;
	getline(cin, input);

	while (!checkValidSpeedSettingsInput(input))
	{
		clearScreen();
		cout << "You enterd incorrect option, please choose again.\n\n";
		printPacmanSpeedOptions();
		getline(cin, input);
	}
	userChoice = stoi(input);
}

void Menu::handleGameMenuGhotsSettingsInput()
{
	string input;
	getline(cin, input);

	while (!checkValidGhostsInput(input))
	{
		clearScreen();
		cout << "You enterd incorrect option, please choose again.\n\n";
		printPacmanGhostsOptions();
		getline(cin, input);
	}
	userChoice = stoi(input);
}


/* This function check valid ghosts settings input*/
bool Menu::checkValidGhostsInput(string input) const
{
	if (input.length() == 1 && userChoice != 0)
	{
		int ghosts = stoi(input);
		if ((ghosts == 1) || (ghosts == 2) || (ghosts == 3) || (ghosts == 4))
			return true;
	}
	return false;
}


/* This function check valid speed settings input*/
bool Menu::checkValidSpeedSettingsInput(string input) const
{
	if (input.length() == 1 && userChoice != 0)
	{
		int speed = stoi(input);
		if ((speed == 1) || (speed == 2) || (speed == 3) || (speed == 4))
			return true;
	}
	return false;
}

void Menu::handleGameMenuSettingsInput(bool getIsColorGame, int currentSpeed, int NumberofGhosts, string screenPath, vector<string> screenNames)
{
	string input;
	getline(cin, input);

	while (!checkValidUserSettings(input))
	{
		clearScreen();
		cout << "You entered incorrect option, please choose again.\n\n";
		printGameSettings(getIsColorGame, currentSpeed, NumberofGhosts, screenPath, screenNames);
		getline(cin, input);
	}
	userChoice = stoi(input);
	//setUserChoice(stoi(input));
}

void Menu::printGameSettings(bool getIsColorGame, int currentSpeed, int NumberofGhosts,
	string screenPath, vector<string> screenNames)
{
	setTextColor(Color::WHITE);
	cout << "Pacman settings:\n"
		"(1) Change color settings (current- ";
	printIsColorGame(getIsColorGame);
	cout << ")\n"
		"(2) Change pacman speed (current - ";
	printCurrentSpeedGame(currentSpeed);
	cout << ")\n"
		"(3) Change number of ghosts (current - ";
	printCurrentNumberOfGhosts(NumberofGhosts);
	cout << ")\n"
		"(4) Choose specific screen from list \n"
		"(5) Back to main menu\n"
		"Choice: ";
}

void Menu::printIsColorGame(bool getIsColorGame)const
{
	if (getIsColorGame)
		cout << "is color game";
	else
		cout << "isn't color game";
}

void Menu::printCurrentSpeedGame(int currentSpeed)const
{
	if (currentSpeed == easyGameSpeed)
		cout << "easy";
	else if (currentSpeed == mediumGameSpeed)
		cout << "medium";
	else if (currentSpeed == hardGameSpeed)
		cout << "hard";
	else // currentSpeed == expertGameSpeed
		cout << "expert";
}

/* This function print the name of the screens in the directory*/
void Menu::printScreenNames(vector<string> screenNames) const
{
	clearScreen();
	cout << "Choose screen from list: \n" << endl;
	for (int i = 0; i < screenNames.size(); i++)
		cout << i + 1 << ") " << screenNames[i] << endl;
	cout << "Choice: ";
}

/* This function handle chosing specific screen*/
void Menu::handleChoseScreen(vector<string> screenNames)
{
	string input;
	getline(cin, input);

	while (!checkValidScreenInput(input))
	{
		clearScreen();
		cout << "You enterd incorrect option, please choose again.\n\n";
		printScreenNames(screenNames);
		getline(cin, input);
	}
	userChoice = stoi(input);
}

/* This function check user input of the screen name*/
bool Menu:: checkValidScreenInput(string input) const
{
	





	if (input.length() == 1 && userChoice != 0)
	{
		int speed = stoi(input);
		if ((speed == 1) || (speed == 2) || (speed == 3) || (speed == 4))
			return true;
	}
	return false;
}
}

void Menu::printCurrentNumberOfGhosts(int NumberofGhosts)const
{
	cout << NumberofGhosts;
}

