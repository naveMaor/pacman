
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Pacman.h"

void Pacman::move()
{
	pacmanBody.draw(' ');
	pacmanBody.move(direction);
	pacmanBody.draw('@');
}

void Pacman::setPacmanBody(int newX, int newY)
{
	pacmanBody.setX(newX);
	pacmanBody.setY(newY);
}

