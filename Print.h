#pragma once
#include <string>
#include <stdio.h>
#include "Utilities.h"
#include "Point.h"

class Print
{
public:
	void winGame(Point gameInfoPosition, bool b_IsColorGame) const;
	void gameOver(Point gameInfoPosition, bool b_IsColorGame) const;
	void resetGameInfoPrints(Point gameInfoPosition) const;
	void printLife(Point gameInfoPosition, bool b_IsColorGame, int playerlife)const;
	void clearCenter()const;
	void printPauseGame() const;
	void printPlayerHitGhost(Point gameInfoPosition, bool b_IsColorGame)const;
	void printScore(Point gameInfoPosition, bool b_IsColorGame, int playerscore)const;
	void removePrintPlayerHitGhost()const;
	//removePacman
};

