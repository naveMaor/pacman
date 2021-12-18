#pragma once
#include "Ghost.h"

class NoviceGhost :public Ghost
{
public:
	NoviceGhost() {};
	~NoviceGhost() { }
	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override;
};

