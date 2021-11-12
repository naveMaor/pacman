// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Ghost.h"

void Ghost::move() 
{
	ghostBody.draw(' ');
	ghostBody.randomMove();
	ghostBody.draw('$');
}

void Ghost::setGhostBody(int newX, int newY)
{
	ghostBody.setX(newX);
	ghostBody.setY(newY);
}

Point Ghost::getGhostBody() const
{
	return ghostBody;
}

