#pragma once
#include "Point_.h"


class Ghost
{
	Point Ghostbody;
	int direction = 3;

public:
	//constractor
	Ghost(int newX, int newY) 
		:	Ghostbody(newX, newY) {};
	//____________________________________________________________________________________________

	//Move ghost radomdly
	void	move();
	//____________________________________________________________________________________________


	//Getters and setters
	void	setGhostBody(int newx, int newy);
	Point	getGhostBody() const;

	

};

