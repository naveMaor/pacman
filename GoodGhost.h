#pragma once
#include "Ghost.h"

class GoodGhost : public Ghost
{
public:
	GoodGhost() {};
	virtual ~GoodGhost() { delete[] this; }
	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override; 

};

