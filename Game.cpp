#include "Game.h"


/* This function handle the game*/
void Game::playGame(bool isSingleGame, string screenName)
{
	int screenCount = 0, numOfScreens = screensNames.size();;	
	alive = true;
	if (isSingleGame)
	{
		if (File::fileToBoard(screenName, board))
			playSingleGame();
	}
	else // full game
	{
		for (int i = 0; i < numOfScreens && alive; i++)
		{
			// If the the file is valid
			if (File::fileToBoard(screensNames[i], board))
				playSingleGame();
		}
	}
}

/* This function play one single game*/
void Game::playSingleGame()
{
	int countMoves = 0;
	bool b_won = false;

	initGame(getIsColorGame());

	while ((player.getLife() > 0) && (!b_won))
	{
		print.printScore(gameInfo, b_IsColorGame, player.getScore());
		fruit.changePosition(board, countMoves);
		ghostsMove(countMoves, player.getBody());
		checkGhostsHit(player.getBody());

		Sleep(gameSpeedVal);
		pacmanMove(board, countMoves);

		checkPacmanHitFruit();

		if (board.getBreadCrumbsLeft() == 0)
		{
			b_won = true;
			print.printScore(gameInfo, b_IsColorGame, player.getScore());
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

/* This fnction init the game*/
void Game::initGame(bool b_color)
{
	clearScreen();
	Hight = board.getBoardHight();
	Width = board.getBoardWidth();
	board.initBoard();
	numOfGhosts = board.getNumOfGhosts();
	gameInfo = board.getInfoPosition();
	gameInfo.setX(gameInfo.getX() + 1);
	board.printBoard();
	setMaxScoreInCurrScreen(board.getBreadCrumbsLeft());
	initGameObj();
	setGameObjectsPositions();

	if (b_color)
		setGameObjectsColors();

	drawGameObj();
	print.printScore(gameInfo, b_IsColorGame, player.getScore());
	print.printLife(gameInfo, b_IsColorGame, player.getLife());
}

/* This function handle settings options*/
void Game::gameSettings()
{
	clearScreen();
	menu.printGameSettings(b_IsColorGame, gameSpeedVal, numOfGhosts, GhostsLevel, screenPath, screensNames);
	menu.handleGameMenuSettingsInput(b_IsColorGame, gameSpeedVal, numOfGhosts, GhostsLevel, screenPath, screensNames);

	switch (menu.getUserChoice())
	{
	case 1:
		chooseColor();
		break;
	case 2:
		gameSpeed();
		break;
	case 3:
		gameGhosts();
		break;
	case 4:
		gameGhostsLevel();
		break;
	case 5:
		clearScreen();
		break;
	default:
		break;
	}
}

void Game::gameGhostsLevel()
{
	clearScreen();
	menu.printPacmanGhostsLevelOptions();
	menu.handleGameMenuGhostsLevelSettingsInput();
	switch (menu.getUserChoice())
	{
	case 1:
		GhostsLevel = easy;
		break;
	case 2:
		GhostsLevel = Medium;
		break;
	case 3:
		GhostsLevel = Hard;
		break;
	default:
		break;
	}
}


void Game::gameGhosts()
{
	clearScreen();
	menu.printPacmanGhostsOptions();
	menu.handleGameMenuGhotsSettingsInput();
	switch (menu.getUserChoice())
	{
	case 1:
		numOfGhosts=1;
		break;
	case 2:
		numOfGhosts=2;
		break;
	case 3:
		numOfGhosts = 3;
		break;
	case 4:
		numOfGhosts = 4;
		break;

	default:
		break;
	}
}

/* This function init the game after ghost hit pacman*/
void Game::initGameAfterGhostHit()
{
	player.setLife(player.getLife() - 1);
	print.printLife(gameInfo, b_IsColorGame,player.getLife());
	
	if (player.getLife() > 0)
	{
		print.printPlayerHitGhost(gameInfo, b_IsColorGame);
		Sleep(shortPauseWindow);
		print.resetGameInfoPrints(gameInfo);
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
		ghosts[i]->removeGhost(board);
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

/* This function handle pacman move*/
void Game::pacmanMove(Board & b, int &countMoves)
{
	getUserKeyboard();
	player.changePosition(b, countMoves);
}

/* This function check if the ghost hit the pacman*/
bool Game::ghostsHit(Point Body)
{
	bool b_Hit = false;
	for (int i = 0; i < numOfGhosts && !b_Hit; i++)
		if (ghosts[i]->ghostHit(Body))
			b_Hit = true;
	return b_Hit;
}

void Game::checkGhostsHit(Point Body)
{
	if (ghostsHit(Body))
	{
		initGameAfterGhostHit();
	}
}


/* This function handle ghosts move*/
void Game::ghostsMove(int & countMoves, Point PlayerLocation)
{
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i]->changePosition(board, countMoves, PlayerLocation);
}


/* This function handle game over*/
void Game::gameOver()
{
	print.gameOver(gameInfo, b_IsColorGame);
	resetGame();
	clearScreen();
}

/* This function print the game before paused*/
void Game::printPreviousGame() const
{
	clearScreen();
	board.printPreviousBoard();
	drawGameObj();
	print.printScore(gameInfo, b_IsColorGame, player.getScore());
	print.printLife(gameInfo, b_IsColorGame, player.getLife());
}

/* This function draw ghosts and player*/
void Game:: drawGameObj() const
{
	player.draw();
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i]->draw();
	fruit.draw();
}

/* This function check if the player eat all breadcrumbs he win!!*/
bool Game:: checkWin() const
{	
	//return 	player.getScore() == maxScoreInCurrScreen;
	return board.getBreadCrumbsLeft() == 0;
}

/* This function handle win situation*/
void Game::winGame()
{
//	setWinnedScore(maxScoreInCurrScreen);
	print.winGame(gameInfo, b_IsColorGame);
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
	{
		switch (GhostsLevel)
		{
		case 1:
		{
			ghosts[i] = new NoviceGhost;
			break;
		}
		case 2:
		{
			ghosts[i] = new GoodGhost;
			break;
		}
		case 3:
		{
			ghosts[i] = new BestGhost;
			break;
		}
		default:
			break;
		}
		ghosts[i]->initGameObject();
	}
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
		gotoxy(pPlayer.getX(), pPlayer.getY());
		player.draw();
		int Oldscore = player.getScore();
		player.setScore(Oldscore + fruit.getFruitScore());
		maxScoreInCurrScreen += fruit.getFruitScore();
		fruit.setshowfruit();
		fruit.setNewFruitlocation(board);
	}
}

void Game::setGameObjectsPositions() 
{
	player.setBody(board.getPacmanStartingPosition());
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i]->setBody(board.getGhostStartingPosition(i));
	fruit.setNewFruitlocation(board);
}

void Game::setGameObjectsColors()
{
	player.setColor(Color::YELLOW);
	for (int i = 0; i < numOfGhosts; i++)
	{
		if (i == 0)
			ghosts[i]->setColor(Color::LIGHTCYAN);
		else if (i == 1)
			ghosts[i]->setColor(Color::LIGHTGREEN);
		else if (i == 2)
			ghosts[i]->setColor(Color::LIGHTBLUE);
		else if (i == 3)
			ghosts[i]->setColor(Color::BROWN);
	}
}

/* This function */
string Game:: choseScreen()
{
	menu.printScreenNames(screensNames);
	return screensNames[menu.getUserChoice()];
}

/* This function handle paused game*/
void Game::pauseGame() const
{
	char ch = 0;
	bool b_Continue = false;

	print.printPauseGame();
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


