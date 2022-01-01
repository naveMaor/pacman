#include "Game.h"


/* This function handle the game*/
void Game::playGame(bool isSingleGame, string screenName)
{
	if (isSingleGame)
	{
		if (File::isValidFile(screenName, board))
			playSingleGame();
		else
		{
			cout << "Isn't valid screen, returning to the menu." << endl;
			Sleep(longPauseWindow);
		}
	}
	else // full game
	{
		size_t numOfScreens = screensNames.size();
		for (auto i = 0; i < numOfScreens && continueGame; i++)
		{
			// If the the file is valid
			if (File::isValidFile(screensNames[i], board))
				playSingleGame();
			else
			{
				cout << "Isn't valid screen, moving to the next screen if exist." << endl;
				Sleep(longPauseWindow);
			}
		}
	}
	resetGame();
}

/* This function play one single game*/
void Game::playSingleGame()
{
	int countMoves = 0;
	bool b_won = false;

	initGame(b_IsColorGame);

	while ((player.getLife() > 0) && (!b_won) && (continueGame))
	{
		
		if (checkWin())
		{
			b_won = true;
			winGame();
		}
		else
		{
			print.printScore(gameInfo, b_IsColorGame, player.getScore());
			fruit.changePosition(board, countMoves);
			ghostsMove(countMoves, player.getBody());
			checkGhostsHit(player.getBody());
			checkPacmanHitFruit();
			Sleep(gameSpeedVal);
			pacmanMove(board, countMoves);
		}		
	}
	// If lose
	if (player.getLife() == 0)
	{
		continueGame = false;
		gameOver();
	}
}

/* This fnction init the game*/
void Game::initGame(bool b_color)
{
	clearScreen();
	board.initBoardData(gameInfo);
	numOfGhosts = board.getNumOfGhosts();
	initGameObj();
	setGameObjectsPositions();

	if (b_color)
		setGameObjectsColors();

	drawGameObj();
	print.printGameInfoAfterPause(gameInfo, b_IsColorGame, player.getScore(), player.getLife());
}

/* This function handle settings options*/
void Game::gameSettings()
{
	clearScreen();
	menu.printGameSettings(b_IsColorGame, gameSpeedVal, GhostsLevel);
	menu.handleGameMenuSettingsInput(b_IsColorGame, gameSpeedVal, GhostsLevel);

	switch (menu.getUserChoice())
	{
	case 1:
		chooseColor();
		break;
	case 2:
		gameSpeed();
		break;
	case 3:
		gameGhostsLevel();
		break;
	case 4:
		clearScreen();
		break;
	default:
		break;
	}
}

/* This function init the ghost level mode*/
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

/* This function init the game after ghost hit pacman*/
void Game::initGameAfterGhostHit()
{
	player.setLife(player.getLife() - 1);
	if (player.getLife() > 0)
	{
		print.printPlayerHitGhost(gameInfo, b_IsColorGame);
		removeGhosts();
		player.remove();
		fruit.removeObject(board);
		setGameObjectsPositions();
		player.setDirection(Stay);
		drawGameObj();
		print.resetGameInfoPrints(gameInfo);
		print.printLife(gameInfo, b_IsColorGame, player.getLife());
	}
}

/* This function remove ghosts last character after pacman hit*/
void Game::removeGhosts()
{
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i]->removeObject(board);
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
			if (continueGame)
			{
				printPreviousGame();
				print.resetGameInfoPrints(gameInfo);
			}
		}
	}
}

/* This function handle pacman move*/
void Game::pacmanMove(Board & b, int &countMoves)
{
	getUserKeyboard();
	if (continueGame)
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

/* This function check ghosts hit*/
void Game::checkGhostsHit(Point Body)
{
	if (ghostsHit(Body))
		initGameAfterGhostHit();
}


/* This function handle ghosts move*/
void Game::ghostsMove(int & countMoves, Point PlayerLocation)
{
	if (numOfGhosts == 1)
		ghosts[0]->changePosition(board, countMoves, PlayerLocation);

	else if (numOfGhosts == 2)
	{
		if(checkGhostCollision(*ghosts[0], *ghosts[1]))
		{
			ghosts[0]->setDirection(Stay);
			ghosts[1]->changePosition(board, countMoves, PlayerLocation);
		}
		else
		{
			ghosts[0]->changePosition(board, countMoves, PlayerLocation);
			ghosts[1]->changePosition(board, countMoves, PlayerLocation);
		}
	}
	else if (numOfGhosts == 3)
	{
		if (checkGhostCollision(*ghosts[0], *ghosts[1]))
		{
			ghosts[0]->setDirection(Stay);
			ghosts[1]->changePosition(board, countMoves, PlayerLocation);
			ghosts[2]->changePosition(board, countMoves, PlayerLocation);
		}
		else if (checkGhostCollision(*ghosts[0], *ghosts[2]))
		{
			ghosts[0]->setDirection(Stay);
			ghosts[1]->changePosition(board, countMoves, PlayerLocation);
			ghosts[2]->changePosition(board, countMoves, PlayerLocation);
		}
		else if (checkGhostCollision(*ghosts[1], *ghosts[2]))
		{
			ghosts[0]->changePosition(board, countMoves, PlayerLocation);
			ghosts[1]->setDirection(Stay);
			ghosts[2]->changePosition(board, countMoves, PlayerLocation);
		}
		else
		{
			ghosts[0]->changePosition(board, countMoves, PlayerLocation);
			ghosts[1]->changePosition(board, countMoves, PlayerLocation);
			ghosts[2]->changePosition(board, countMoves, PlayerLocation);
		}
	}
	else if (numOfGhosts == 4)
		for (int i = 0; i < numOfGhosts; i++)
			ghosts[i]->changePosition(board, countMoves, PlayerLocation);
}

/* This function check ghost collision*/
bool Game::checkGhostCollision(Ghost &g1, Ghost &g2)
{
	if (g1.getBody() == g2.getBody())
		return true;
	else
		return false;
}


/* This function handle game over*/
void Game::gameOver()
{
	print.gameOver(gameInfo, b_IsColorGame);
	for (int i = 0; i < numOfGhosts; i++)
		delete ghosts[i];
	clearScreen();
}

/* This function print the game before paused*/
void Game::printPreviousGame() const
{
	clearScreen();
	board.printBoard();
	drawGameObj();
	print.printGameInfoAfterPause(gameInfo, b_IsColorGame, player.getScore(), player.getLife());	
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
	return board.getBreadCrumbsLeft() <= 0;
}

/* This function handle win situation*/
void Game::winGame()
{
	print.printScore(gameInfo, b_IsColorGame, player.getScore());
	print.winGame(gameInfo, b_IsColorGame);
	resetGame();
	clearScreen();
	setTextColor(Color::WHITE);
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
	setTextColor(Color::WHITE);
	player.setScore(0);
	continueGame = true;
	singleGame = false;
	board.resetBoardDataMembers();
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
			ghosts[i] = new NoviceGhost();
			break;
		}
		case 2:
		{
			ghosts[i] = new GoodGhost();
			break;
		}
		case 3:
		{
			ghosts[i] = new BestGhost();
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

/* This function check if pacman hit fruit*/
void Game::checkPacmanHitFruit()
{
	Point pPlayer = player.getBody();
	Point pFruit = fruit.getBody();

	if ((pPlayer == pFruit) && fruit.getshowfruit())
	{
		gotoxy(pPlayer.getX(), pPlayer.getY());
		player.draw();
		int Oldscore = player.getScore();
		player.setScore(Oldscore + fruit.getFruitScore());
		fruit.setshowfruit();
		fruit.setNewFruitlocation(board);
	}
}

/* This function set the game object position from board*/
void Game::setGameObjectsPositions() 
{
	player.setBody(board.getPacmanStartingPosition());
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i]->setBody(board.getGhostStartingPosition(i));
	fruit.setNewFruitlocation(board);
}

/* This function set game object color if this is color game*/
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
	fruit.setColor(Color::LIGHTRED);
}

/* This function handle choosing specific screen*/
string Game:: choseScreen()
{
	menu.printScreenNames(screensNames);
	return screensNames[menu.getUserChoice()];
}

/* This function handle paused game*/
void Game::pauseGame() 
{
	char ch = 0;
	bool b_Continue = false;

	print.printPauseGame(gameInfo);
	while (!b_Continue)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
				b_Continue = true;
			else if (ch == 'g' || ch == 'G')
			{
				b_Continue = true;
				exitGame();
			}
		}
	}
}

/* This function exit game*/
void Game :: exitGame()
{
	continueGame = false;
	clearScreen();
}
