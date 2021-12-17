#include "Game.h"

int main()
{
	Game game;
	Menu menu;
	string screen = game.getScreenNames()[0];

	setTextColor(Color::WHITE);
	int userChoice = menu.menu();
	while (userChoice != 9)
	{
		switch (userChoice)
		{
		case 1: // all game
		{
			game.playGame(false, screen);
			break;
		}
		case 2: // single game
		{
			screen = menu.handleChooseScreen(game.getScreenNames());
			game.playGame(true, screen);
			break;
		}
		case 3:
		{
			game.gameSettings();
			break;
		}
		case 8:
		{
			menu.printInstructions();
			break;
		}
		default:
		{
			cout << "You entered incorrect option, please enter again!" << endl;
			break;
		}	
		}
		clearScreen();
		setTextColor(Color::WHITE);
		userChoice = menu.menu();
	}

	clearScreen();
	setTextColor(Color::WHITE);
	cout << "Bye Bye!\n"
		"Thank you for playing with us!" << endl;
	return 0;
}
