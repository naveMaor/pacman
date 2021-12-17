#include "Game.h"

/* This function handle the game*/
void Game::playGame()
{
	vector<string> screensNames = File::getScreensName(PATH);
	int countMoves = 0, screenCount = 0, numOfScreens = screensNames.size();;
	bool b_won = false, alive = true;
	
	for (int i = 0; i < numOfScreens && alive; i++)
	{
		// If the the file is valid
		if (File::fileToBoard(screensNames[i], board))
		{
			initGame(getIsColorGame());

			while ((player.getLife() > 0) && (!b_won))
			{
				print.printScore(b_IsColorGame, player.getScore());
				fruit.fruitPlay(countMoves, board);

				if (countMoves % 3 == 0)
					ghostsMove();

				Sleep(gameSpeedVal);
				pacmanMove(board);
				countMoves++;
		
				if (ghostsHit())
					initGameAfterGhostHit();

				checkPacmanHitFruit();

				if (checkWin())
				{
					b_won = true;
					print.printScore(b_IsColorGame, player.getScore());
					winGame();
				}
			}	
			// If lose
			if (player.getLife() == 0)
			{
				alive = false;
				gameOver();
			}
		}
	}	
}

/* This fnction init the game*/
void Game::initGame(bool b_color)
{
	clearScreen();
	Hight = board.getBoardHight();
	Width = board.getBoardWidth();
	board.initBoard();
	numOfGhosts = board.getNumOfGhosts();
	setGameObjectsPositions();
	
	board.printBoard();
	setMaxScoreInCurrScreen(board.getBreadCrumbsCount());
	initGameObj();

	if (b_color)
		setGameObjectsColors();

	drawGameObj();
	print.printScore(b_IsColorGame, player.getScore());
	print.printLife(b_IsColorGame, player.getLife());
}

/* This function handle settings options*/
void Game::gameSettings()
{
	clearScreen();
	menu.printGameSettings(b_IsColorGame, gameSpeedVal);
	menu.handleGameMenuSettingsInput(b_IsColorGame, gameSpeedVal);

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
	print.printLife(b_IsColorGame,player.getLife());
	
	if (player.getLife() > 0)
	{
		print.printPlayerHitGhost(b_IsColorGame);
		Sleep(shortPauseWindow);
		print.removePrintPlayerHitGhost();
		removeGhosts();
		player.remove();
		setGameObjectsPositions();
		player.setDirection(Stay);
		drawGameObj();
	}
}

/* This function remove ghosts last character after pacman hit*/
void Game::removeGhosts()
{
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i].removeGhost(board);
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
			print.pauseGame();
			printPreviousGame();
		}	
	}
}


/* This function handle pacman move*/
void Game::pacmanMove(Board & b)
{
	getUserKeyboard();
	player.changePosition(b);
}

/* This function check if the ghost hit the pacman*/
bool Game::ghostsHit()
{
	bool b_Hit = false;
	for (int i = 0; i < numOfGhosts && !b_Hit; i++)
		if (ghostHit(ghosts[i]))
			b_Hit = true;
	return b_Hit;
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
	for (int i = 0; i < numOfGhosts; i++)
		GhostchangeSmartPosition(ghosts[i]);
}


/* This function handle game over*/
void Game::gameOver()
{
	print.gameOver(b_IsColorGame);
	resetGame();
	clearScreen();
}

/* This function print the game before paused*/
void Game::printPreviousGame() const
{
	clearScreen();
	board.printPreviousBoard();
	drawGameObj();
	print.printScore(b_IsColorGame, player.getScore());
	print.printLife(b_IsColorGame, player.getLife());
}

/* This function draw ghosts and player*/
void Game:: drawGameObj() const
{
	player.draw();
	
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i].draw();
	
	fruit.draw();
}

/* This function check if the player eat all breadcrumbs he win!!*/
bool Game:: checkWin() const
{	
	return 	player.getScore() == maxScoreInCurrScreen;
	//return 	player.getScore() == 10;
}

/* This function handle win situation*/
void Game::winGame()
{
	setWinnedScore(maxScoreInCurrScreen);
	print.winGame(b_IsColorGame);
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

/* This function reset the game when starting again*/
void Game::resetGame()
{
	initGameObj();
	player.setScore(0);
	setGameObjectsPositions();
	board.resetBoard();
}

/* This function init pacman and ghosts*/
void Game::initGameObj()
{
	player.initGameObject();
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i].initGameObject();
	fruit.initGameObject();
}

/* This function handle the speed of the game settings*/
void Game::gameSpeed()
{
	clearScreen();
	menu.printPacmanSpeedOptions();
	menu.handleGameMenuSpeedSettingsInput();
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

void Game::checkPacmanHitFruit()
{
	Point pPlayer = player.getBody();
	Point pFruit = fruit.getBody();

	if (pPlayer == pFruit)
	{
		int Oldscore = player.getScore();
		player.setScore(Oldscore + fruit.getFruitScore());
		maxScoreInCurrScreen += fruit.getFruitScore();
		fruit.setshowfruit();
		gotoxy(pPlayer.getX(), pPlayer.getY());
		player.draw();
	}
}


Point Game::minDistance(Point GhostLocation, Point PlayerLocation)
{
	Point Pcurr(0, 0);
	QItem source(PlayerLocation.getX(), PlayerLocation.getY(), Pcurr);

	// To keep track of visited QItems. Marking
	// blocked cells as visited.
	bool visited[HIGHT][WIDTH] = { false };
	// init source
	source.row = PlayerLocation.getX();
	source.col = PlayerLocation.getY();

	// applying BFS on matrix cells starting from source
	std::queue<QItem> q;
	q.push(source);
	visited[source.col][source.row] = true;
	while (!q.empty())
	{
		QItem curr = q.front();
		q.pop();

		// Destination found;
		if (GhostLocation.getX() == curr.row && GhostLocation.getY() == curr.col)
			return curr.p;

		Pcurr.setX(curr.row);
		Pcurr.setY(curr.col);

		// moving right
		if (curr.row + 1 < Width && player.checkValidPos(curr.row + 1, curr.col, board) && visited[curr.col][curr.row + 1] == false)
		{
			q.push(QItem(curr.row + 1, curr.col, Pcurr));
			visited[curr.col][curr.row + 1] = true;
		}
		// moving down
		if (curr.col + 1 < Hight && player.checkValidPos(curr.row, curr.col + 1, board) && visited[curr.col + 1][curr.row] == false)
		{
			q.push(QItem(curr.row, curr.col + 1, Pcurr));
			visited[curr.col + 1][curr.row] = true;
		}

		// moving left
		if (curr.row - 1 >= 0 && player.checkValidPos(curr.row - 1, curr.col, board) && visited[curr.col][curr.row - 1] == false)
		{
				q.push(QItem(curr.row - 1, curr.col, Pcurr));
				visited[curr.col][curr.row - 1] = true;
		}
		
		// moving up
		if (curr.col - 1 >= 0 && player.checkValidPos(curr.row, curr.col - 1, board) && visited[curr.col - 1][curr.row] == false)
		{
				q.push(QItem(curr.row, curr.col - 1, Pcurr));
				visited[curr.col - 1][curr.row] = true;
		}		
	}
	Point p1(-1, -1);
	return p1;
}


void Game::GhostchangeSmartPosition(Ghost& G)
{
	Point newPoint = minDistance(G.getBody(), player.getBody());
	Point tmp(-1, -1);
	int x = G.getBody().getX();
	int y = G.getBody().getY();
	if (newPoint == tmp)
	{

	}
	else
	{
		G.changedirectionbyPoint(newPoint);
		G.moveAndDraw();

		// If last ghost position was breadcrumb print breadcrumb
		if (board.getBoardValFromPoint(x, y) == bc)
			G.printBreadCrumbs(x, y);
	}
}

void Game::setGameObjectsPositions() 
{
	player.setBody(board.getPacmanStartingPosition());
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i].setBody(board.getGhostStartingPosition(i));
}

void Game::setGameObjectsColors()
{
	player.setColor(Color::YELLOW);
	for (int i = 0; i < numOfGhosts; i++)
	{
		if (i == 0)
			ghosts[i].setColor(Color::LIGHTCYAN);
		else if (i == 1)
			ghosts[i].setColor(Color::LIGHTGREEN);
		else if (i == 2)
			ghosts[i].setColor(Color::LIGHTBLUE);
		else if (i == 3)
			ghosts[i].setColor(Color::BROWN);
	}
}