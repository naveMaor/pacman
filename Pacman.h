#pragma once
#include "Point.h"

class Pacman
{
private:
	// Pacman data members
	Point pacmanBody;
	int score = 0;
	int life = 3;
	int direction = 4;
	Color color;

public:
	// Constractor
	Pacman(int newX, int newY):pacmanBody(newX, newY) {};

	// Pacman functions
	void move();

	//Getters and setters
	int getDirection() const;
	void setDirection(int newDirection);
	int	getScore() const { return score; };
	void setPlusScore() { score++; }
	int	getLife() const { return life; };
	void setMinusLife() { life--; }
	Point getPacmanBody();
	void setPacmanBody(int x, int y);
	Color getColor() { return color; };
	void setColor(Color color);
};

