#include "Game.h"


///* This function get user choice of menu*/
//int Game::menu()
//{
//	printGameMenu();
//	string input;
//	getline(cin, input);
//
//	/* If the user enter invalid option clear and ignore cin input */
//	while (!checkValidUserInput(input))
//	{
//		clearScreen();
//		cout << "You enterd incorrect option, please choose again.\n\n";
//		printGameMenu();
//		getline(cin, input);
//	}
//	//userChoice = stoi(input);
//	setUserChoice(stoi(input));
//
//	//return userChoice;
//	return getUserChoice();
//}
//
//void Game::printGameMenu() const
//{
//	cout << "Welcome to PacmanGame \n"
//		"(1) Start a new game\n"
//		"(2) Game settings\n"
//		"(8) Present instructions and keys\n"
//		"(9) EXIT\n";
//}
//
//
//
///* This function print pacman instructions*/
//void Game::printInstructions() const
//{
//	clearScreen();
//	cout << "Pacman game instructions:\n"
//		"The purpose of the game is to eat all the breadcrumbs (dots).\n"
//		"If pacman makes contact with a ghost, he will lose a life.\n"
//		"The game ends when all lives are lost.\n\n"
//		"The keys:\n"
//		"Up- 'w' or 'W'\n"
//		"Down- 'x' or 'X'\n"
//		"Left- 'a' or 'A'\n"
//		"Right- 'd' or 'D'\n"
//		"Stay- 's' or 'S'\n"
//		"Pause/continue the game- ESC\n\n"
//		"Press any key to return the menu\n";
//
//	char c = _getch();
//	clearScreen();
//}
//
///* This function prints the pacman speed settings options*/
//void Game::printPacmanSpeedOptions() const
//{
//	setTextColor(Color::WHITE);
//	cout << "Please enter pacman speed\n"
//		"1. Easy\n"
//		"2. Medium\n"
//		"3. Hard\n"
//		"4. Expert\n\n"
//		"Choice: ";
//}
//

//
///* Check if user input is correct*/
//bool Game::checkValidUserInput(string input) const
//{
//	if (input.length() == 1)
//	{
//		char chUser = stringToChar(input);
//		if (chUser >= '0' && chUser <= '9')
//			if ((chUser == '1') || (chUser == '2') || (chUser == '8') || (chUser == '9'))
//				return true;
//	}
//	return false;
//}
///* This function change string to char*/
//char Game::stringToChar(string& s) const
//{
//	char res = s[0];
//	return res;
//}
//
//
///* This function check valid user input*/
//bool Game::checkValidUserSettings(string input) const
//{
//	//if (input.length() == 1 && userChoice != 0)
//	if (input.length() == 1 && menu.getUserChoice() != 0)
//	{
//		int userChoice = stoi(input);
//		if ((userChoice == 1) || (userChoice == 2) || (userChoice == 3))
//			return true;
//	}
//	return false;
//}
//
//
///* This function handle game menu speed settings input*/
//void Game::handleGameMenuSpeedSettingsInput()
//{
//	string input;
//	getline(cin, input);
//
//	while (!checkValidSpeedSettingsInput(input))
//	{
//		clearScreen();
//		cout << "You enterd incorrect option, please choose again.\n\n";
//		menu.printPacmanSpeedOptions();
//		getline(cin, input);
//	}
//	//userChoice = stoi(input);
//	menu.setUserChoice(stoi(input));
//
//}
//
///* This function check valid speed settings input*/
//bool Game::checkValidSpeedSettingsInput(string input) const
//{
//	if (input.length() == 1 && menu.getUserChoice() != 0)
//	{
//		int speed = stoi(input);
//		if ((speed == 1) || (speed == 2) || (speed == 3) || (speed == 4))
//			return true;
//	}
//	return false;
//}




/* This function handle the game*/
void Game::playGame()
{
	int countGhostMove = 0;
	bool b_won = false;

	initGame(getIsColorGame());

	while ((player.getLife() > 0) && (!b_won))
	{
		printScore();

		if (countGhostMove == 2)
		{
			ghostsMove();
			countGhostMove = 0;
		}
		else
		{
			Sleep(gameSpeedVal);
			pacmanMove();
			countGhostMove++;
		}
		if (ghostsHit())
			initGameAfterGhostHit();

		if (checkWin())
		{
			b_won = true;
			printScore();
			winGame();
		}
	}	

	// If lose
	if(player.getLife() == 0)
		gameOver();
}

/* This fnction init the game*/
void Game::initGame(bool b_color)
{
	clearScreen();
	board.printBoard();
	initGameObj();

	if (b_color) {
		player.setColor(Color::YELLOW);
		ghostOne.setColor(Color::LIGHTGREEN);
		ghostTwo.setColor(Color::LIGHTCYAN);
	}

	drawGameObj();
	printScore();
	printLife();
}

/* This function handle settings options*/
void Game::gameSettings()
{
	clearScreen();
	printGameSettings();
	handleGameMenuSettingsInput();

	switch (menu.getUserChoice())
	{
	case 1:
		chooseColor();
		break;
	case 2:
		gameSpeed();
		break;
	case 3:
		clearScreen();
		break;
	default:
		break;
	}
}

/* This function init the game after ghost hit pacman*/
void Game::initGameAfterGhostHit()
{
	player.setLife(player.getLife() - 1);
	printLife();
	
	if (player.getLife() > 0)
	{
		printPlayerHitGhost();
		Sleep(shortPauseWindow);
		removePrintPlayerHitGhost();
		removeGhosts();
		removePacman();
		player.setBody(pacmanStartX, pacmanStartY);
		player.setDirection(4);
		ghostOne.setBody(ghostOneStartX, ghostOneStartY);
		ghostTwo.setBody(ghostTwoStartX, ghostTwoStartY);
		drawGameObj();
	}
}

void Game::printPlayerHitGhost() const
{
	if (getIsColorGame())
		setTextColor(Color::RED);
	gotoxy(26, 23);
	cout << "You hit the ghost!" << endl;
}

void Game::removePrintPlayerHitGhost() const
{
	gotoxy(26, 23);
	cout << "                     ";
}

/* This function remove pacman last character after ghost hit*/
void Game::removePacman()
{
	gotoxy(player.getBody().getX(), player.getBody().getY());
	cout << (char)space;
}

/* This function remove ghosts last character after pacman hit*/
void Game::removeGhosts()
{
	removeGhost(ghostOne);
	removeGhost(ghostTwo);
}

/* This function remove ghost last character after pacman hit*/
void Game::removeGhost(Ghost ghost)
{
	int x = ghost.getBody().getX();
	int y = ghost.getBody().getY();
	gotoxy(x, y);
	if (ifLastGhostPositionWasBreadcrumb(x, y))
		printBreadCrumbs(x, y);
	else
		cout << (char)space;
}

/* This function get the user key board hit*/
void Game::getUserKeyboard()
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();

		// Down
		if ((ch == 'x') || (ch == 'X'))
			player.setDirection(3);

		// UP
		else if ((ch == 'w') || (ch == 'W'))
			player.setDirection(2);

		// Left
		else if ((ch == 'a') || (ch == 'A'))
			player.setDirection(0);
		
		// Right
		else if ((ch == 'd') || (ch == 'D'))
			player.setDirection(1);
		
		// Stay
		else if ((ch == 's') || (ch == 'S'))
			player.setDirection(4);

		// ESC 
		else if (ch == 27)
		{
			pauseGame();
			printPreviousGame();
		}	
	}
}

/* This function handle paused game*/
void Game::pauseGame()
{
	char ch = 0;
	bool b_Continue = false;

	setTextColor(Color::WHITE);
	clearCenter();
	gotoxy(27, 9);
	cout << "Game paused!";
	gotoxy(27, 11);
		cout << "Press ESC to continue";
	
	while (!b_Continue)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
				b_Continue = true;
		}	
	}
}

/* This function handle pacman move*/
void Game::pacmanMove()
{
	getUserKeyboard();

	int x = player.getBody().getX();
	int y = player.getBody().getY();

	Point nextPos = player.getBody();
	nextPos.move(player.getDirection());
	

	unsigned char charAtnextPoint = board.getBoardValFromPoint(nextPos.getX(), nextPos.getY());
	unsigned char charAtPoint = board.getBoardValFromPoint(x, y);

	// If player is going through tunnel
	if (charAtnextPoint == space)
	{
		if (charAtPoint == bc) // if there was at curr pos then raise score
		{
			player.setPlusScore();
			board.setBoardValByPoint(x, y);
		}

		if (x == 1) {
			player.getBody().draw(space);
			player.setBody(69, y);
		}

		else if (x == 68) {
			player.getBody().draw(space);
			player.setBody(0, y);
		}
		else if (y == 1)
		{
			player.getBody().draw(space);
			player.setBody(x, 19);
		}
		else if (y == 18)
		{
			player.getBody().draw(space);
			player.setBody(x, 0);
		}
		player.move();
	}

	// if there is wall in the next move
	else if (charAtnextPoint == w)
		player.setDirection(4);

	else
	{
		// if there breadcrumb
		if (charAtPoint == bc)
		{
			player.setPlusScore();
		}
		board.setBoardValByPoint(x, y);
		player.move();
	}
}

/* This function check if the ghost hit the pacman*/
bool Game::ghostsHit()
{
	return(ghostHit(ghostOne) || ghostHit(ghostTwo));
}

/* This function handle ghost hit*/
bool Game::ghostHit(Ghost ghost)
{
	if (ghost.getBody() == player.getBody())
		return true;
	return false;
}

/* This function handle ghosts move*/
void Game::ghostsMove()
{
	ghostRandomMove(ghostOne);
	ghostRandomMove(ghostTwo);
}

/* This function handle ghost randome move*/
void Game::ghostRandomMove(Ghost& ghost)
{
	int x = ghost.getBody().getX();
	int y = ghost.getBody().getY();
	int direction = rand() % 4;
	
	// If wall get new random direction
	while (!checkGhostValidMove(x, y, direction))
		direction = rand() % 4;	
		
	ghost.setDirection(direction); 
	ghost.move();

	// If last ghost position was breadcrumb print breadcrumb
	if (ifLastGhostPositionWasBreadcrumb(x, y))
		printBreadCrumbs(x, y);
}

/* This function print breadcrumbs at point*/
void Game::printBreadCrumbs(int x, int y)
{
	unsigned char breadCrumb = bc;
	setTextColor(Color::WHITE);
	gotoxy(x, y);
	cout << breadCrumb;
}

/* This function check if ghost next move is valid */
bool Game::checkGhostValidMove(int x, int y, int dir)
{
	ghostIlustrateNextMove(x, y, dir);
	unsigned char charAtNextPoint = board.getBoardValFromPoint(x, y);

	// If the ghost out of board
	if ((x == 69) || (x == 0) || (y == 0) || (y == 19))
		return false;

	// If the next move is wall, tunnel or ghost this isn't valid move
	if ((charAtNextPoint == w) || (charAtNextPoint == space) || (charAtNextPoint == ghostIcon ))
		return false;
	
	return true;
}

/* This function ilustrate the next ghost move*/
void Game::ghostIlustrateNextMove(int& x, int& y, int dir)
{
	switch (dir)
	{
	case 0: // LEFT
		x--;
		break;
	case 1: // RIGHT
		x++;
		break;
	case 2: // UP
		y--;
		break;
	case 3: // DOWN
		y++;
		break;
	}
}

/* This function check if in the last position of the ghost was bread crumbs*/
bool Game::ifLastGhostPositionWasBreadcrumb(int x, int y)
{
	if (board.getBoardValFromPoint(x, y) == bc)
		return true;
	return false;
}

/* This function print pacman score*/
void Game::printScore() const
{
	setTextColor(Color::WHITE);
	gotoxy(38, 21);
	cout << "Pacman Score: ";
	if (getIsColorGame())
		setTextColor(Color::YELLOW);
	cout << player.getScore();
}

/* This function print pacman life*/
void Game::printLife() const
{
	setTextColor(Color::WHITE);
	resetPrintLife();
	gotoxy(16, 21);
	cout << "Remaining lives: "; 
	if(getIsColorGame())
		setTextColor(Color::LIGHTRED);
	for (int i = 0; i < player.getLife(); i++)
		cout << (char)heart;	
}

void Game::resetPrintLife() const
{
	gotoxy(16, 21);
	cout << "                     ";
}

/* This function handle game over*/
void Game::gameOver()
{
	if (getIsColorGame())
		setTextColor(Color::LIGHTRED);
	gotoxy(30, 23);
	cout << "You losed!";
	Sleep(longPauseWindow);
	resetGame();
	clearScreen();
}



/* This function print the game before paused*/
void Game::printPreviousGame() const
{
	clearScreen();
	board.printPreviousBoard();
	player.draw();
	ghostOne.draw();
	ghostTwo.draw();
	printScore();
	printLife();
}

/* This function draw ghosts and player*/
void Game:: drawGameObj() const
{
	player.draw();
	ghostOne.draw();
	ghostTwo.draw();
}

/* This function check if the player eat all breadcrumbs he win!!*/
bool Game:: checkWin() const
{
	return player.getScore() == 1092;
}

/* This function handle win situation*/
void Game::winGame()
{
	if(getIsColorGame())
		setTextColor(Color::GREEN);
	gotoxy(26, 23);	
	cout << "You won the game!!!" << endl;
	Sleep(longPauseWindow);
	resetGame();
	clearScreen();
}



/* This function*/
void Game::chooseColor()
{
	char colorChoice = 'd';
	clearScreen();
	menu.printColorMenu();
	colorChoice = _getch();

	while (colorChoice != 'y' && colorChoice != 'Y' && colorChoice != 'n' && colorChoice != 'N' && !_kbhit())
	{
		clearScreen();
		cout << "You entered incorrect option, please enter again" << endl;
		menu.printColorMenu();
		colorChoice = _getch();
	}

	if (colorChoice == 'y' || colorChoice == 'Y')
	{
		setIsColorGame(true);
		clearScreen();
		cout << "You will play with colors!" << endl;
	}
	else if (colorChoice == 'n' || colorChoice == 'N')
	{
		setIsColorGame(false);
		clearScreen();
		cout << "You will play without colors!" << endl;
	}

	cout << "Press any key to return the menu\n" << endl;

	char c = _getch();
	clearScreen();
}

/* This function clear the center of the screen when pausing the game*/
void Game::clearCenter() const
{
	for (int j = 0; j < 5; j++)
	{
		gotoxy(20, 8 + j);
		cout << "                                  ";
	}
}

/* This function reset the game when starting again*/
void Game::resetGame()
{
	initGameObj();
	player.setBody(pacmanStartX, pacmanStartY);
	ghostOne.setBody(ghostOneStartX, ghostOneStartY);
	ghostTwo.setBody(ghostTwoStartX, ghostTwoStartY);
	board.resetBoard();
}

/* This function init pacman and ghosts*/
void Game::initGameObj()
{
	player.initPacman();
	initGhosts();
}

/* This function init ghosts*/
void Game::initGhosts()
{
	ghostOne.initGameObject();
	ghostTwo.initGameObject();
}






/* This function handle the speed of the game settings*/
void Game::gameSpeed()
{
	clearScreen();
	menu.printPacmanSpeedOptions();
	menu.handleGameMenuSpeedSettingsInput();
	//switch (userChoice)
	switch (menu.getUserChoice())
	{
	case 1:
		setGameSpeed(easyGameSpeed);
		break;
	case 2:
		setGameSpeed(mediumGameSpeed);
		break;
	case 3:
		setGameSpeed(hardGameSpeed);
		break;
	case 4:
		setGameSpeed(expertGameSpeed);
		break;

	default:
		break;
	}
}

/* This function print game settings options*/
void Game::printGameSettings() const
{
	setTextColor(Color::WHITE);
	cout << "Pacman settings:\n"
		"(1) Change color settings (current- ";
	printIsColorGame();
	cout << ")\n"
		"(2) Change pacman speed (current - ";
	printCurrentSpeedGame();
	cout << ")\n"
		"(3) Back to main menu";
	cout << "\n"
		"Choice: ";
}


void Game::printIsColorGame() const
{
	if (getIsColorGame())
		cout << "is color game";
	else
		cout << "isn't color game";
}

/* This function handle the game menu settings input*/
void Game::handleGameMenuSettingsInput()
{
	string input;
	getline(cin, input);

	while (!menu.checkValidUserSettings(input))
	{
		clearScreen();
		cout << "You entered incorrect option, please choose again.\n\n";
		printGameSettings();
		getline(cin, input);
	}
	menu.setUserChoice(stoi(input));
}





/* This function print current speed game*/
void Game::printCurrentSpeedGame() const
{
	int currentSpeed = getGameSpeedVal();

	if (currentSpeed == easyGameSpeed)
		cout << "easy";
	else if (currentSpeed == mediumGameSpeed)
		cout << "medium";
	else if (currentSpeed == hardGameSpeed)
		cout << "hard";
	else // currentSpeed == expertGameSpeed
		cout << "expert";
}

/* This function init fruit location*/
void Game::initFruit()
{

	Point fruitLocation(rand() % (Width-1) + 0, rand() % (Hight-1) + 0);

	while (fruitLocation == ghostOne.getBody() ||
		fruitLocation == ghostTwo.getBody() ||
		fruitLocation == player.getBody() ||
		board.getBoardValFromPoint(fruitLocation.getX(), fruitLocation.getY()) == w)
	{
		fruitLocation.setX(rand() % Width + 0);
		fruitLocation.setY(rand() % Hight + 0);
	}

	fruit.setFruitBody(fruitLocation);

}
bool Game::ghostHitFruit()
{
	return false;
}
bool Game::pacmanHitFruit()
{
	return false;
}
void Game::unDisplayFruit()
{

}

void Game::fruitMove()
{

}