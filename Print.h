#pragma once
#include <string>
#include <stdio.h>
#include "Utilities.h"

class Print
{
public:
	void winGame(bool b_IsColorGame) const;
	void gameOver(bool b_IsColorGame) const;
	void resetPrintLife(bool b_IsColorGame) const;
	void printLife(bool b_IsColorGame, int playerlife)const;
	void clearCenter()const;
	void pauseGame() const;
	void printPlayerHitGhost(bool b_IsColorGame)const;
	void printScore(bool b_IsColorGame, int playerscore)const;
	void removePrintPlayerHitGhost()const;
	//removePacman
};

