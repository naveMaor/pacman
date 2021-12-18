#pragma once
#include "Ghost.h"


class BestGhost :public Ghost
{
public:
	BestGhost() {};
	virtual ~BestGhost() { }

	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override;
};


