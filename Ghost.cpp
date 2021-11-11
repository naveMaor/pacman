// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Ghost.h"

void Ghost::move() 
{
	Ghostbody.draw(' ');
	Ghostbody.randomMove();
	Ghostbody.draw('$');
}

void Ghost::setGhostBody(int newX, int newY)
{
	Ghostbody.setX(newX);
	Ghostbody.setY(newY);
}

Point Ghost::getGhostBody() const
{
	return Ghostbody;
}