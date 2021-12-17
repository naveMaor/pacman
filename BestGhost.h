#pragma once
#include "Ghost.h"


class BestGhost :public Ghost
{
public:
	BestGhost() {};
	virtual ~BestGhost() { delete[] this; }

	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override;
};


