#pragma once
#include "Ghost.h"


class BestGhost :public Ghost
{
public:
	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override;
};


