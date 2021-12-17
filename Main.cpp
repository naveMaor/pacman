#include "Game.h"

int main()
{
	Game game;
	Menu menu;

	setTextColor(Color::WHITE);
	int userChoice = menu.menu();
	while (userChoice != 9)
	{
		switch (userChoice)
		{
		case 1: // all game
		{
			game.playGame(false);
			break;
		}
		case 2: // single game
		{
			menu.handleChooseScreen(game.getScreenNames());
			game.playGame(true);
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
