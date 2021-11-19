#pragma once
#include "Point.h"

class Ghost
{
	// Ghost data members
	Point ghostBody;
	Color color = WHITE;
	int direction = 3;

public:
	// Constractor
	Ghost();
	Ghost(int newX, int newY) : ghostBody(newX, newY) {};

	// Ghost functions
	void move();
	void draw();
	void setGhostBody(int newX, int newY);
	Point getGhostBody() const;
	void setGhostDirection(int direction);
	Color getColor() const { return color; };
	void setColor(Color color);
	void initGhost();
};

