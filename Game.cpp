#include "Game.h"

/* This function handle the game*/
void Game::playGame(bool isSingleGame, string screenName, bool isSaveMode, bool isLoadMode, bool isSilentMode)
{
	if (isSingleGame)
		playByMode(screenName, isSaveMode, isLoadMode, isSilentMode);
	else // full game
	{
		size_t numOfScreens = screensNames.size();
		for (auto i = 0; i < numOfScreens && continueGame; i++)
			playByMode(screensNames[i], isSaveMode, isLoadMode, isSilentMode);
	}
	resetGame();
}

/* This function play one single game*/
void Game::playSingleGame(string screenName)
{
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
			ghostsMove(player.getBody());
			checkGhostsHit(player.getBody());
			checkPacmanHitFruit();
			Sleep(gameSpeedVal);
			pacmanMove(board);
		}		
	}
	// If lose
	if (player.getLife() == 0)
	{
		continueGame = false;
		gameOver();
	}
}

void Game::playSaveSingleGame(string screenName)
{
	bool b_won = false;
	initGame(b_IsColorGame);

	// Open result file
	File::createAndOpenFile(screenName, fileType::result);

	while ((player.getLife() > 0) && (!b_won) && (continueGame))
	{
		if (checkWin())
		{
			writeWinToResultFile();
			File::closeWrittenFile();
			writeStepsToFile(screenName);
			b_won = true;
			winGame();
		}
		else
		{
			print.printScore(gameInfo, b_IsColorGame, player.getScore());
			fruit.changePosition(board, countMoves);
			ghostsMove(player.getBody());
			checkAndSaveGhostsHit(player.getBody());
			checkPacmanHitFruit();
			Sleep(gameSpeedVal);
			pacmanMove(board);
		}
	}

	// If lose
	if (player.getLife() == 0)
	{
		// Close result file
		File::closeWrittenFile();
		// Writes Steps
		writeStepsToFile(screenName);

		continueGame = false;
		gameOver();
	}
}


/* This function split steps by objects */
string Game::splitObjectStepsByDel(string currGameStep, string objectDelimeter, int &start, int &end)
{
	string objectStep = currGameStep.substr(start, end - start);
	start = end + objectDelimeter.size();
	end = currGameStep.find(objectDelimeter, start);
	return objectStep;
}

/* This function init silent game*/
void Game::initSilentGame()
{
	board.initBoardData(gameInfo);
	numOfGhosts = board.getNumOfGhosts();
	initGameObj();
	setGameObjectsPositions();
}

/* This function init the game*/
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
void Game::pacmanMove(Board & b)
{
	getUserKeyboard();
	if (continueGame)
		player.changePosition(b, countMoves);
}

/* This function check if the ghost hit the pacman*/
bool Game::ghostsHit(Point pacmanBody)
{
	bool b_Hit = false;
	for (int i = 0; i < numOfGhosts && !b_Hit; i++)
		if (ghosts[i]->ghostHit(pacmanBody))
			b_Hit = true;
	return b_Hit;
}

/* This function check ghosts hit*/
void Game::checkGhostsHit(Point pacmanBody)
{
	if (ghostsHit(pacmanBody))
		initGameAfterGhostHit();
}

/* This function check ghosts hit and write to result file*/
void Game::checkAndSaveGhostsHit(Point pacmanBody)
{
	if (ghostsHit(pacmanBody))
	{
		writeDeathToResultFile();
		initGameAfterGhostHit();
	}
}


/* This function handle ghosts move*/
void Game::ghostsMove(Point PlayerLocation)
{
	if (numOfGhosts == 1)
		ghosts[0]->changePosition(board, countMoves, PlayerLocation);

	else if (numOfGhosts == 2)
	{
		if(checkGhostsCollision(*ghosts[0], *ghosts[1]))
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
		if (checkGhostsCollision(*ghosts[0], *ghosts[1]))
		{
			ghosts[0]->setDirection(Stay);
			ghosts[1]->changePosition(board, countMoves, PlayerLocation);
			ghosts[2]->changePosition(board, countMoves, PlayerLocation);
		}
		else if (checkGhostsCollision(*ghosts[0], *ghosts[2]))
		{
			ghosts[0]->setDirection(Stay);
			ghosts[1]->changePosition(board, countMoves, PlayerLocation);
			ghosts[2]->changePosition(board, countMoves, PlayerLocation);
		}
		else if (checkGhostsCollision(*ghosts[1], *ghosts[2]))
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
bool Game::checkGhostsCollision(Ghost &g1, Ghost &g2)
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
	player.setScore(0);
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
	countMoves = 0;
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
		fruit.setShowFruit();
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

/* This function write to the current cordinates of pacman death to result file*/
void Game::writeDeathToResultFile()
{
	File::writeStringToFile("D");
	File::writeCharToFile('|');
	File::writeCordinateToFileAsChar(static_cast<char>(player.getBody().getX()));
	File::writeCharToFile(',');
	File::writeCordinateToFileAsChar(static_cast<char>(player.getBody().getY()));
	File::writeCharToFile('|');
	File::writeCountMovesToFileAsChar(countMoves);
	File::writeCharToFile('|');
	File::writeStringToFile(" moves.");
	File::writeCharToFile('\n');
}

/* This function write to the current cordinates of pacman win to result file*/
void Game::writeWinToResultFile()
{
	File::writeStringToFile("W");
	File::writeCharToFile('|');
	File::writeCordinateToFileAsChar(static_cast<char>(player.getBody().getX()));
	File::writeCharToFile(',');
	File::writeCordinateToFileAsChar(static_cast<char>(player.getBody().getY()));
	File::writeCharToFile('|');
	File::writeCountMovesToFileAsChar(countMoves);
	File::writeCharToFile('|');
	File::writeStringToFile(" moves.");
	File::writeCharToFile('\n');
}

void Game::writeStepsToFile(const string& screenName)
{
	File::createAndOpenFile(screenName, fileType::step);

	// Write num of ghosts
	File::writeCharToFile(numOfGhosts + '0');
	File::writeCharToFile('\n');

	std::pair<char, char> pFruitLocation;
	for (int i = 0; i < countMoves; i++)
	{

		// Write fruit values
		pFruitLocation = fruit.getValueFromLocationVector(i);
		File::writeCharToFile('(');
		File::writeCordinateToFileAsChar(pFruitLocation.first);
		File::writeCharToFile(',');
		File::writeCordinateToFileAsChar(pFruitLocation.second);
		File::writeCharToFile(')');
		File::writeCharToFile(fruit.getValueFromScoreVector(i));
		File::writeCharToFile(fruit.getValueFromisShowVector(i));
		File::writeCharToFile(fruit.getValueFromStepsVector(i));

		// Seperate
		File::writeCharToFile('|');

		// Write player steps
		File::writeCharToFile(player.getValueFromStepsVector(i));

		// Seperate
		File::writeCharToFile('|');

		// Write ghosts steps
		for (int j = 0; j < numOfGhosts; j++)
			File::writeCharToFile(ghosts[j]->getValueFromStepsVector(i));

		File::writeCharToFile('\n');
	}

	File::closeWrittenFile();
	resetVectors();
}

/* This function reset steps vectors*/
void Game::resetVectors() {
	player.clearStepsVector();
	player.clearLivesVector();
	fruit.clearVectors();
	for (int j = 0; j < numOfGhosts; j++)
		ghosts[j]->clearStepsVector();
}


/* This function play the game by requierd mode*/
void Game:: playByMode(string screenName, bool isSaveMode, bool isLoadMode, bool isSilentMode)
{
	if (File::isValidFile(screenName, board))
	{
		if (isSaveMode)
			playSaveSingleGame(screenName);
		else if (isLoadMode && isSilentMode)
		{
			playLoadSilentGame(screenName);
		}
		else if (isLoadMode)
			playLoadSingleGame(screenName);



		else
			playSingleGame(screenName);
	}
	else
	{
		cout << "Isn't valid screen, returning to the menu." << endl;
		Sleep(longPauseWindow);
	}
}



void Game::playLoadSingleGame(string screenName)
{
	string currGameStep, objectDelimeter = "|", stepsFileData;
	int numOfGhost, countMoves = 0;
	bool b_won = false;

	initGame(b_IsColorGame);

	stepsFileData = File::readFileToString(screenName, fileType::step);
	stringstream stream(stepsFileData);
	numOfGhost = stepsFileData[0] - '0';

	// Move to the begining of moves
	getline(stream, currGameStep, '\n');

	// Get step section
	while (getline(stream, currGameStep, '\n') && (!b_won)&& (player.getLife() > 0))
	{
		LoadModeDataParameters(countMoves, numOfGhost, currGameStep, objectDelimeter);

		print.printScore(gameInfo, b_IsColorGame, player.getScore());
		fruit.move();
		Ghost::loadModeMove(board, ghosts, numOfGhost);
		checkGhostsHit(player.getBody());
		checkPacmanHitFruit();
		Sleep(100);
		player.loadModeMove(board);

		if (checkWin())
		{
			b_won = true;
			winGame();
		}
	}

	// If lose
	if (player.getLife() == 0)
	{
		continueGame = false;
		gameOver();
	}
}



void Game::playLoadSilentGame(string screenName)
{
	string currGameStep, objectDelimeter = "|", resultsFileData, StepsFileData;
	int  numOfGhost, countMoves = 0;
	bool b_won = false;
	char W_or_D;
	Point resultPlayerloaction;
	int resultFileMove, resultMovesNumber;

	resultsFileData = File::readFileToString(screenName, fileType::result);
	StepsFileData = File::readFileToString(screenName, fileType::step);
	stringstream resultstream(resultsFileData);
	stringstream Stepstream(StepsFileData);
	LoadsilentModeDataParameters(resultPlayerloaction, W_or_D, resultMovesNumber, resultsFileData, objectDelimeter);


	numOfGhost = StepsFileData[0] - '0';

	// Move to the begining of moves
	getline(Stepstream, currGameStep, '\n');

	// Get step section
	while (getline(Stepstream, currGameStep, '\n') && (!b_won) && (player.getLife() > 0))
	{

		LoadModeDataParameters(countMoves, numOfGhost, currGameStep, objectDelimeter);
		fruit.getBody().move(fruit.getDirection());
		GhostsSilentModeMove();
		if (ghostsHit(player.getBody()))
		{
			if (W_or_D != 'D' || resultPlayerloaction != player.getBody() || countMoves != resultMovesNumber)
			{
				cout << " test failed " << endl;
				return;
			}
		}
		player.getBody().move(player.getDirection());

		if (checkWin())
		{
			winGame();
			b_won = true;
			if (W_or_D != 'W' || resultPlayerloaction != player.getBody() || countMoves != resultMovesNumber)
			{
				cout << " test failed " << endl;
				return;
			}
				cout << "screen " <<screenName <<" passed" << endl;
				Sleep(longPauseWindow);
			
		}
	}

	if (player.getLife() == 0)
	{
		continueGame = false;
		cout << "screen " << screenName << " over" << endl;
		gameOver();
	}
}


void Game::LoadsilentModeDataParameters(Point & resultPlayerloaction, char& W_or_D,int& MovesNumber, string& resultline,string objectDelimeter)
{
	int x, y;
	int start = 0, end = resultline.find(objectDelimeter);
	
	W_or_D = resultline[0];
	LoadDataFromLine(x, y, 2, resultline);
	resultPlayerloaction.setX(x);
	resultPlayerloaction.setX(y);
	end = resultline.find(objectDelimeter);
	splitObjectStepsByDel(resultline, objectDelimeter, start, end);
	resultline = splitObjectStepsByDel(resultline, objectDelimeter, start, end);
	MovesNumber = LoadNumberFromLine(resultline, 0);
}


void Game::LoadModeDataParameters(int& countMoves, int numOfGhost, string& currGameStep, string& objectDelimeter)
{
	int start = 0;
	int end = currGameStep.find(objectDelimeter);
	countMoves++;

	// Set Directions
	fruit.setFromStepFile(splitObjectStepsByDel(currGameStep, objectDelimeter, start, end));
	player.setDirectionFromStepFile(splitObjectStepsByDel(currGameStep, objectDelimeter, start, end));
	string ghostsMove = splitObjectStepsByDel(currGameStep, objectDelimeter, start, end);
	Ghost::setGhostsDirectionFromStepFile(ghosts, numOfGhost, ghostsMove);

}
//todo:transfer to generic class!!!
void Game::LoadDataFromLine(int& x,int &y, int startindex, string& LineData)
{
	x = LineData[startindex] - '0';
	if (LineData[startindex+1] != ',')
	{
		x = (x * 10) + LineData[startindex+1] - '0';
		y = LineData[startindex+3] - '0';
		if (LineData[startindex+4] != '|')
		{
			y = (y * 10) + LineData[startindex+4] - '0';
		}
	}
	else
	{
		y = LineData[startindex+2] - '0';
		if (LineData[startindex+3] != '|')
		{
			y = (y * 10) + LineData[startindex+3] - '0';
		}
	}
}


int Game::LoadNumberFromLine(string& LineData , int index)
{
	int x = LineData[index] - '0';
	index++;
	while (LineData[index]>='0'&& LineData[index] <= '9')
	{
		x = (x * 10) + LineData[index] - '0';
	}
	return x;
}

void Game::GhostsSilentModeMove()
{
	for (int i = 0; i < numOfGhosts; i++)
	{
		ghosts[i]->getBody().move(ghosts[i]->getDirection());
	}
}