// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Game.h"

/* This function get user choice of menu*/
int Game::menu()
{
	setTextColor(WHITE);
	cout << "Welcome to PacmanGame \n"
		"(1) Start a new game\n"
		"(8) Present instructions and keys\n"
		"(9) EXIT\n"
		"\nChoice: "<< endl;

	cin >> userChoice;
	return userChoice;
}

/* This function handle the game*/
void Game::playGame()
{
	bool b_ghostMoved = false;

	initGame();
	
	while (player.getLife() > 0)
	{
		printScore();
		if (!b_ghostMoved)
		{
			pacmanMove();
			ghostsMove();
			b_ghostMoved = true;
		}
		else
		{
			pacmanMove();
			b_ghostMoved = false;
		}

		if (ghostsHit())
			initGameAfterGhostHit();
	}
}

/* This fnction init the game*/
void Game::initGame()
{
	clear_screen();
	board.printBoard();
	player.setColor(YELLOW);
	ghostOne.setColor(LIGHTGREEN);
	ghostTwo.setColor(LIGHTCYAN);
	printScore();
	printLife();
}

/* This function init the game after ghost hit pacman*/
void Game::initGameAfterGhostHit()
{
	player.setMinusLife();
	removePacman();
	removeGhosts();
	player.setPacmanBody(1, 1);
	player.setDirection(4);
	ghostOne.setGhostBody(50,14);
	ghostTwo.setGhostBody(10,3);
	printLife();
}

/* This function remove pacman last character after ghost hit*/
void Game::removePacman()
{
	gotoxy(player.getPacmanBody().getX(), player.getPacmanBody().getY());
	cout << ' ';
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
		cout << ' ';
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

	clear_screen();
	gotoxy(0, 0);
	cout << "Game paused!\n"
		"Press ESC to continue";
	
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
	if (charAtnextPoint == ' ')
	{
		if (charAtPoint == 250) // if there was at curr pos then raise score
		{
			player.setPlusScore();
			board.setBoardValByPoint(x, y);
		}

		if (x == 1) {
			player.getPacmanBody().draw(' ');
			player.setPacmanBody(69, y);
		}

		else if (x == 68) {
			player.getPacmanBody().draw(' ');
			player.setPacmanBody(0, y);
		}
		else if (y == 1)
		{
			player.getPacmanBody().draw(' ');
			player.setPacmanBody(x, 19);
		}
		else if (y == 18)
		{
			player.getPacmanBody().draw(' ');
			player.setPacmanBody(x, 0);
		}
		player.move();
	}

	//if  there is wall in the next move
	else if (charAtnextPoint == 219)
		player.setDirection(4);

	else
	{
		if (charAtPoint == 250)
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
	return(ghostHit(ghostOne) && ghostHit(ghostTwo));
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
	Sleep(700);
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
	unsigned char breadcrumb = 250;
	setTextColor(WHITE);
	gotoxy(x, y);
	cout << breadcrumb;
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
	if ((charAtNextPoint == 219) || (charAtNextPoint == ' ') || (charAtNextPoint == '$' ))
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
	if (board.getBoardValFromPoint(x, y) == 250)
		return true;
	return false;
}

/* This function print pacman life*/
void Game::printLife() {
	setTextColor(WHITE);
	gotoxy(28, 22);
	cout << "Remaining lives: " << player.getLife();
}

/* This function print pacman score*/
void Game::printScore() {
	setTextColor(WHITE);
	gotoxy(28, 21);
	cout << "Pacman Score: " << player.getScore();
}

/* This function handle game over*/
void Game::gameOver()
{
	Sleep(4000);
	clear_screen();
	gotoxy(0, 0);
	cout << "You losed!" << endl;
}

/* This function print pacman instructions*/
void Game::printInstructions()
{
	clear_screen();
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
	
	_getch();
	clear_screen();
}

/* This function print the game before paused*/
void Game::printPreviousGame()
{
	clear_screen();
	board.printPreviousBoard();
	player.getPacmanBody().draw('@');
	ghostOne.getGhostBody().draw('$');
	ghostTwo.getGhostBody().draw('$');
}
