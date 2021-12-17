#pragma once
#include "Ghost.h"

class GoodGhost : public Ghost
{
public:
	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override;
};

