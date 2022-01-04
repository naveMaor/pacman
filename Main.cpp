#include "Game.h"
#include "InputParser.h"

int main(int argc, char** argv) {
	Game game;
	Menu menu;
	//string screen = game.getScreenNames()[0];
	string screen = File::getScreensName(screenPath)[0];
	InputParser input(argc, argv);

	if (input.cmdOptionExists("-silent"))
	{

		if (input.cmdOptionExists("-load")) 
		{
			// Do Load with silet stuff
		}
		else
		{
			cout << "wrong input" << endl;
			return 0;
		}
	}
	else if (input.cmdOptionExists("-load"))
	{
		// Do Load only stuff
	}
	else
	{
		setTextColor(Color::WHITE);
		int userChoice = menu.menu();
		while (userChoice != 9)
		{
			switch (userChoice)
			{
			case 1: // all game
			{
				if (input.cmdOptionExists("-save"))
					game.playGame(false, screen, true);
				else
					game.playGame(false, screen, false);
				break;
			}
			case 2: // single game
			{
				screen = menu.handleChooseScreen(File::getScreensName(screenPath));
				if (input.cmdOptionExists("-save"))
					game.playGame(true, screen, true);
				else
					game.playGame(true, screen, false);
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
	}

	clearScreen();
	setTextColor(Color::WHITE);
	cout << "Bye Bye!\n"
		"Thank you for playing with us!" << endl;
  
    return 0;
}

