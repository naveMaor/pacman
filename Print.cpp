#include "Print.h"


void Print::winGame(Point gameInfoPosition, bool b_IsColorGame) const
{
	if (b_IsColorGame)
		setTextColor(Color::GREEN);
	resetGameInfoPrints(gameInfoPosition);
	gotoxy(gameInfoPosition.getX(), gameInfoPosition.getY());
	cout << "You won the game!!!!" << endl;
	Sleep(longPauseWindow);
}

void Print::gameOver(Point gameInfoPosition, bool b_IsColorGame) const
{
	if (b_IsColorGame)
		setTextColor(Color::LIGHTRED);
	resetGameInfoPrints(gameInfoPosition);
	gotoxy(gameInfoPosition.getX() + 5, gameInfoPosition.getY());
	cout << "You lost!!";
	Sleep(longPauseWindow);
}

void Print::resetGameInfoPrints(Point gameInfoPosition) const
{
	gotoxy(gameInfoPosition.getX(), gameInfoPosition.getY());
	cout << "~~~~~~~~~~~~~~~~~~~~";
	gotoxy(gameInfoPosition.getX(), gameInfoPosition.getY() + 1);
	cout << "                    ";
	gotoxy(gameInfoPosition.getX(), gameInfoPosition.getY() + 2);
	cout << "~~~~~~~~~~~~~~~~~~~~";

}

/* This function print pacman life*/
void Print::printLife(Point gameInfoPosition, bool b_IsColorGame, int playerlife)const
{
	setTextColor(Color::WHITE);
	gotoxy(gameInfoPosition.getX(), gameInfoPosition.getY() + 1);
	cout << "Life:";
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
void Print::printPlayerHitGhost(Point gameInfoPosition, bool b_IsColorGame)const
{
	if (b_IsColorGame)
		setTextColor(Color::RED);
	resetGameInfoPrints(gameInfoPosition);
	gotoxy(gameInfoPosition.getX(), gameInfoPosition.getY() + 1);
	cout << "You hit the ghost!!!" << endl;
	Sleep(shortPauseWindow);
	resetGameInfoPrints(gameInfoPosition);
}


/* This function print pacman score*/
void Print::printScore(Point gameInfoPosition,  bool b_IsColorGame, int playerScore)const
{
	setTextColor(Color::WHITE);
	gotoxy(gameInfoPosition.getX() + 10, gameInfoPosition.getY() + 1);
	cout << "Score:";
	if (b_IsColorGame)
		setTextColor(Color::YELLOW);
	cout << playerScore;
}
