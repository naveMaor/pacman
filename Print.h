#pragma once
#include <string>
#include <stdio.h>
#include "Utilities.h"
#include "Point.h"

class Print
{
public:
	void winGame(bool b_IsColorGame) const;
	void gameOver(bool b_IsColorGame) const;
	void resetPrintLife(Point gameInfoPosition) const;
	void printLife(Point gameInfoPosition, bool b_IsColorGame, int playerlife)const;
	void clearCenter()const;
	void printPauseGame() const;
	void printPlayerHitGhost(bool b_IsColorGame)const;
	void printScore(Point gameInfoPosition, bool b_IsColorGame, int playerscore)const;
	void removePrintPlayerHitGhost()const;
	//removePacman
};

