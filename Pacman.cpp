
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Pacman.h"

int Pacman::getDirection() const
{
	return direction;
}

void Pacman::setDirection(int newDirection)
{
	direction = newDirection;
}

void Pacman::move()
{
	pacmanBody.draw(' ');
	pacmanBody.move(direction);
	setTextColor(color);
	pacmanBody.draw('@');
}

void Pacman:: draw()
{
	setTextColor(color);
	pacmanBody.draw('@');
}

Point Pacman::getPacmanBody()
{
	return pacmanBody;
}

void Pacman::setPacmanBody(int x, int y)
{
	pacmanBody.setX(x);
	pacmanBody.setY(y);
}

void Pacman::setColor(Color color)
{
	this->color = color;
}