#pragma once
#include "Point.h"


class Ghost
{
	Point ghostBody;
	int direction = 3;

public:
	Ghost();

	//constractor
	Ghost(int newX, int newY) : ghostBody(newX, newY) {};
	//____________________________________________________________________________________________

	//Move ghost radomdly
	void	move();
	//____________________________________________________________________________________________


	//Getters and setters
	void	setGhostBody(int newx, int newy);
	Point	getGhostBody() const;
	void setGhostDirection(int direction);

	

	

};

