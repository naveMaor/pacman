#pragma once

#include "Point_.h"


class Pacman
{
private:
	Point pacmanBody;
	int score = 0;
	int life = 3;
	int direction = 3;


public:
	Pacman();
	void move();
	const void getDirection();
	void setDirection(int direction);
	const int getScore() { return score; };
	const int getLife() { return life; };
	void setNewLife() { life--; }
	void setNewScore() { score++; }
	void setPacmanBody(int x, int y) {}

};

