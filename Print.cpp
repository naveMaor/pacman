#include "Print.h"


void Print::winGame(bool b_IsColorGame) const
{
	if (b_IsColorGame)
		setTextColor(Color::GREEN);
	gotoxy(26, 23);
	cout << "You won the game!!!" << endl;
	Sleep(longPauseWindow);
}

void Print::gameOver(bool b_IsColorGame) const
{
	if (b_IsColorGame)
		setTextColor(Color::LIGHTRED);
	gotoxy(30, 23);
	cout << "You lost!";
	Sleep(longPauseWindow);
}

void Print::resetPrintLife(Point gameInfoPosition) const
{
	gotoxy(gameInfoPosition);
	cout << "                  ";
}

/* This function print pacman life*/
void Print::printLife(Point gameInfoPosition, bool b_IsColorGame, int playerlife)const
{
	setTextColor(Color::WHITE);
	resetPrintLife(gameInfoPosition);
	gotoxy(gameInfoPosition.getX() + 1, gameInfoPosition.getY());
	cout << "Lives: ";
	if (b_IsColorGame)
		setTextColor(Color::LIGHTRED);
	for (int i = 0; i < playerlife; i++)
		cout << (char)heart;
}
/* This function clear the center of the screen when pausing the game*/

void Print::clearCenter()const
{
	for (int j = 0; j < 5; j++)
	{
		gotoxy(20, 8 + j);
		cout << "                                  ";
	}
}

void Print::printPauseGame() const
{
	setTextColor(Color::WHITE);
	clearCenter();
	gotoxy(27, 9);
	cout << "Game paused!";
	gotoxy(27, 11);
	cout << "Press ESC to continue";
}

/* This function print player hit ghost message*/
void Print::printPlayerHitGhost(bool b_IsColorGame)const
{
	if (b_IsColorGame)
		setTextColor(Color::RED);
	gotoxy(26, 23);
	cout << "You hit the ghost!" << endl;
}


/* This function print pacman score*/
void Print::printScore(Point gameInfoPosition,  bool b_IsColorGame, int playerScore)const
{
	setTextColor(Color::WHITE);
	gotoxy(38, 21);
	cout << "Pacman Score: ";
	if (b_IsColorGame)
		setTextColor(Color::YELLOW);
	cout << playerScore;
}


/* This function remove player hit ghost message*/
void Print::removePrintPlayerHitGhost()const
{
	gotoxy(26, 23);
	cout << "                     ";
}
