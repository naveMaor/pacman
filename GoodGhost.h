#pragma once
#include "Ghost.h"

class GoodGhost : public Ghost
{
public:
	GoodGhost() {};

	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override; //
};

