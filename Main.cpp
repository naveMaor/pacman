// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Game.h"

int main()
{
	Game game;
	int userChoice = game.menu();
	while (userChoice != 9)
	{
		switch (userChoice)
		{
		case 1:
		{
			game.setIsColorGame(true);
			game.playGame();
			break;
		}
		case 2:
		{
			game.gameSettings();
			userChoice = game.menu();
			game.playGame();
			break;
		}
		case 8:
		{
			game.printInstructions();
			break;
		}
		default:
		{
			cout << "You entered incorrect option, please enter again!" << endl;
			break;
		}	
		}
		userChoice = game.menu();
	}

	clearScreen();
	setTextColor(WHITE);
	cout << "Bye Bye!\n"
		"Thank you for playing with us!" << endl;
	return 0;
}