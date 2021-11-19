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
	Color color = WHITE;

public:
	// Constractor
	Pacman(int newX, int newY):pacmanBody(newX, newY) {};

	// Pacman functions
	void move();
	void draw();

	//Getters and setters
	int getDirection() const;
	void initPacman();
	void setDirection(int newDirection);
	int	getScore() const { return score; };
	void setScore(int x) { score = x; };
	void setPlusScore() { score++; }
	int	getLife() const { return life; };
	void setLife() { life = 3; };
	void setMinusLife() { life--; }
	Point getPacmanBody();
	void setPacmanBody(int x, int y);
	Color getColor() { return color; };
	void setColor(Color color);
};

