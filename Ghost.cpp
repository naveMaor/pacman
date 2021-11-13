// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Ghost.h"

void Ghost::move() 
{
	ghostBody.draw(' ');
	ghostBody.move(direction);
	setTextColor(color);
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

void Ghost::setGhostDirection(int direction)
{
	this->direction = direction;
}

void Ghost::setColor(Color color)
{
	this->color = color;
}