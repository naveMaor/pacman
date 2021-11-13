// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Game.h"

int Game::menu()
{
	cout << "Welcome to PacmanGame \n"
		"(1) Start a new game\n"
		"(8) Present instructions and keys\n"
		"(9) EXIT\n"
		"\nChoice: "<< endl;

	cin >> userChoice;
	return userChoice;
}

void Game::playGame(int userChoice)
{
	//while (userChoice != 9)
	//
		switch (userChoice)
		{
		case 1:
			clear_screen();
			initGame();

			break;

		case 8:
			break;

		case 9:
			break;

		}
	//}
	
}

void Game::initGame()
{
	board.printBoard();
	player.getPacmanBody().draw('@');
	while (player.getLife() > 0)
	{
		if (PacmanHitGhost(ghostOne, player) || PacmanHitGhost(ghostTwo, player))
		{
			
		}
		ghostRandomMove(ghostOne);
		ghostRandomMove(ghostTwo);
		
	}
	
}

void Game::pacmanMove()
{
	int x = player.getPacmanBody().getX();
	int y = player.getPacmanBody().getY();

	Point nextPos = player.getPacmanBody();
	nextPos.move(player.getDirection());

	unsigned char charAtnextPoint = board.getBoardValFromPoint(nextPos.getX(), nextPos.getY());
	unsigned char charAtPoint = board.getBoardValFromPoint(x, y);


	if (charAtnextPoint == ' ')
	{
		if (charAtPoint == 250)
		{
			player.setScore();
			board.setBoardValByPoint(x, y);
		}
		player.getPacmanBody().draw(' ');

		if (x == 0)
			player.setPacmanBody(70, y);
		else if (x == 70)
			player.setPacmanBody(0, y);
		else if (y == 0)
			player.setPacmanBody(x, 20);
		else if (y == 20)
			player.setPacmanBody(x, 0);
		else
			player.move();

		player.getPacmanBody().draw('@');
	}

	// If breadcrumbes
	else if (charAtPoint == 250 && charAtnextPoint != 219)
	{
		player.setScore();
		board.setBoardValByPoint(x, y);
		player.move();
	}

	// If wall
	else if (charAtnextPoint == 219)
		player.setDirection(4);

	// Tunnels
	else {
		player.move();
	}
}


bool Game::PacmanHitGhost(Ghost g1, Pacman player)
{
	Point Ppacman = player.getPacmanBody();
	Point Pghost = g1.getGhostBody();

	if (Ppacman.getX() == Pghost.getX() && Ppacman.getY() == Pghost.getY())
	{
		return true;
	}
	return false;
}

// The ghost eats walls and get out of the board!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Game::ghostRandomMove(Ghost& ghost)
{
	int x = ghost.getGhostBody().getX();
	int y = ghost.getGhostBody().getY();
	int direction = rand() % 4;

	// If wall
	while (!checkGhostValidMove(x, y, direction))
		direction = rand() % 4;
	
	// Food
	ghost.setGhostDirection(direction); 
	ghost.move();
	
	if (ifLastGhostPositionWasFood(x, y))
		printBreadCrumbs(x, y);

	sleep(10000);
}

void Game::printBreadCrumbs(int x, int y)
{
	unsigned char bc = 250;
	gotoxy(x, y);
	cout << bc;
}

/* This function check if ghost next move is valid */
bool Game::checkGhostValidMove(int x, int y, int dir)
{
	ghostNextMove(x, y, dir);
	unsigned char charAtNextPoint = board.getBoardValFromPoint(x, y);

	// If the ghost out of board
	if ((x == 70) || (x == 0) || (y == 0) || (y == 20))
		return false;

	// If the next move is wall, tunnel or ghost this isn't valid move
	if ((charAtNextPoint == 219) || (charAtNextPoint == ' ') || (charAtNextPoint == '$'))
		return false;
	return true;
}

/* This function ilustrate the next ghost move*/
void Game::ghostNextMove(int& x, int& y, int dir)
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

bool Game::ifLastGhostPositionWasFood(int x, int y)
{
	if (board.getBoardValFromPoint(x, y) == 250)
		return true;
	return false;
}