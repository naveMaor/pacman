#include "Game.h"
#include "InputParser.h"

int main(int argc, char** argv) {
    Game game;
    Menu menu;
    string screen = game.getScreenNames()[0];

    setTextColor(Color::WHITE);
    int userChoice = menu.menu();

    InputParser input(argc, argv);
    if (input.cmdOptionExists("-silent")) {

        if (input.cmdOptionExists("-load")) {
            // Do Load with silet stuff
        }
        else
        {
            cout << "wrong input";
            return 0;
        }
    }
    else if (input.cmdOptionExists("-load")) {
        // Do Load only stuff
    }
    if (input.cmdOptionExists("-save")) {
		setTextColor(Color::WHITE);
		int userChoice = menu.menu();
		while (userChoice != 9)
		{
			switch (userChoice)
			{
			case 1: // all game
			{
				game.playGame(false, screen, false);
				break;
			}
			case 2: // single game
			{
				screen = menu.handleChooseScreen(game.getScreenNames());
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

		clearScreen();
		setTextColor(Color::WHITE);
		cout << "Bye Bye!\n"
			"Thank you for playing with us!" << endl;

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
				game.playGame(false, screen, true);
				break;
			}
			case 2: // single game
			{
				screen = menu.handleChooseScreen(game.getScreenNames());
				game.playGame(true, screen, true);
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
	}
    return 0;
}

