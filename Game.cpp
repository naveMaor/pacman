// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Game.h"

/* This function get user choice of menu*/
int Game::menu()
{
	printGameMenu();
	cin >> userChoice;

	/* If the user enter invalid option clear and ignore cin input */
	if (!checkValidUserInput(userChoice))
	{
		std::cin.clear();
		std::cin.ignore();
		clearScreen();
		cout << "You enterd incorrect option, please choose again.\n\n";
		menu();
	}	
	return userChoice;
}

void Game::printGameMenu()
{
	setTextColor(WHITE);
	cout << "Welcome to PacmanGame \n"
		"(1) Start a new game\n"
		"(8) Present instructions and keys\n"
		"(9) EXIT\n"
		"\nChoice: " << endl;
}

/* This function handle the game*/
void Game::playGame()
{
	chooseColor();
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
			Sleep(pacmanSpeed);
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
	if (b_color) {
		player.setColor(YELLOW);
		ghostOne.setColor(LIGHTGREEN);
		ghostTwo.setColor(LIGHTCYAN);
	}
	drawGameObj();
	printScore();
	printLife();
}

/* This function init the game after ghost hit pacman*/
void Game::initGameAfterGhostHit()
{
	player.setMinusLife();
	
	if (player.getLife() > 0)
	{
		printPlayerHitGhost();
		Sleep(shortPauseWindow);
		removePrintPlayerHitGhost();
		removePacman();
		removeGhosts();
		player.setPacmanBody(pacmanStartX, pacmanStartY);
		player.setDirection(4);
		ghostOne.setGhostBody(ghostOneStartX, ghostOneStartY);
		ghostTwo.setGhostBody(ghostTwoStartX, ghostTwoStartY);
		drawGameObj();
		printLife();
	}
}

void Game::printPlayerHitGhost()
{
	if (getIsColorGame())
		setTextColor(RED);
	gotoxy(26, 23);
	cout << "You hit the ghost!" << endl;
}

void Game::removePrintPlayerHitGhost()
{
	gotoxy(26, 23);
	cout << "                     ";
}

/* This function remove pacman last character after ghost hit*/
void Game::removePacman()
{
	gotoxy(player.getPacmanBody().getX(), player.getPacmanBody().getY());
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
	int x = ghost.getGhostBody().getX();
	int y = ghost.getGhostBody().getY();
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

	//clearScreen();
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

	int x = player.getPacmanBody().getX();
	int y = player.getPacmanBody().getY();

	Point nextPos = player.getPacmanBody();
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
			player.getPacmanBody().draw(space);
			player.setPacmanBody(69, y);
		}

		else if (x == 68) {
			player.getPacmanBody().draw(space);
			player.setPacmanBody(0, y);
		}
		else if (y == 1)
		{
			player.getPacmanBody().draw(space);
			player.setPacmanBody(x, 19);
		}
		else if (y == 18)
		{
			player.getPacmanBody().draw(space);
			player.setPacmanBody(x, 0);
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
	if (ghost.getGhostBody() == player.getPacmanBody())
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
	int x = ghost.getGhostBody().getX();
	int y = ghost.getGhostBody().getY();
	int direction = rand() % 4;
	
	// If wall get new random direction
	while (!checkGhostValidMove(x, y, direction))
		direction = rand() % 4;	
		
	ghost.setGhostDirection(direction); 
	ghost.move();

	// If last ghost position was breadcrumb print breadcrumb
	if (ifLastGhostPositionWasBreadcrumb(x, y))
		printBreadCrumbs(x, y);
}

/* This function print breadcrumbs at point*/
void Game::printBreadCrumbs(int x, int y)
{
	unsigned char breadCrumb = bc;
	setTextColor(WHITE);
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
void Game::printScore() {
	setTextColor(WHITE);
	gotoxy(38, 21);
	cout << "Pacman Score: " << player.getScore();
}

/* This function print pacman life*/
void Game::printLife() {
	setTextColor(WHITE);
	gotoxy(16, 21);
	cout << "Remaining lives: " << player.getLife();
}

/* This function handle game over*/
void Game::gameOver()
{
	if (getIsColorGame())
		setTextColor(LIGHTRED);
	gotoxy(30, 23);
	cout << "You losed!";
	Sleep(longPauseWindow);
	clearScreen();
}

/* This function print pacman instructions*/
void const Game ::printInstructions()
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

/* This function print the game before paused*/
void const Game::printPreviousGame()
{
	clearScreen();
	board.printPreviousBoard();

	player.getPacmanBody().draw(pacmanIcon);
	ghostOne.getGhostBody().draw(ghostIcon);
	ghostTwo.getGhostBody().draw(ghostIcon);
	printScore();
	printLife();
}

/* This function draw ghosts and player*/
void Game:: drawGameObj()
{
	player.draw();
	ghostOne.draw();
	ghostTwo.draw();
}

/* Thsi function check if the player eat all breadcrumbs he win*/
bool Game:: checkWin()
{
	return player.getScore() == 1092;
}

/* This function handle win situation*/
void const Game::winGame()
{
	if(getIsColorGame())
		setTextColor(GREEN);
	gotoxy(26, 23);	
	cout << "You won the game!!!" << endl;
	Sleep(longPauseWindow);
	clearScreen();
}

/* Check if user input is correct*/
bool Game::checkValidUserInput(int userChoice)
{
	if ((userChoice == 1) || (userChoice == 8) || (userChoice == 9))
		return true;
	return false;
}

/* This function*/
void Game::chooseColor()
{
	char colorChoice = 'd';
	clearScreen();
	cout << "Do you want to use colors in the game?" << endl;
	cout << "Press Y for yes or N for no" << endl;
	colorChoice = _getch();

	while (colorChoice != 'y' && colorChoice != 'Y' && colorChoice != 'n' && colorChoice != 'N' && !_kbhit())
	{
		clearScreen();
		cout << "You entered incorrect option, please enter again" << endl;
		cout << "Do you want to use colors in the game?" << endl;
		cout << "Press Y for yes or N for no" << endl;
		colorChoice = _getch();
	}

	if (colorChoice == 'y' || colorChoice == 'Y')
	{
		setIsColorGame(true);
		cout << "\nYou will play with colors!" << endl;
	}
	else if (colorChoice == 'n' || colorChoice == 'N')
	{
		setIsColorGame(false);
		cout << "\nYou will play without colors!" << endl;
	}
	cout << "The game will start automaticliy in " << shortPauseWindow/1000 << " seconds.";
	Sleep(shortPauseWindow);
	clearScreen();
}

/* This function clear the center of the screen when pausing the game*/
void Game::clearCenter()
{
	for (int j = 0; j < 5; j++)
	{
		gotoxy(20, 8 + j);
		cout << "                                  ";
	}
}