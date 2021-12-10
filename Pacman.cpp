#include "Pacman.h"

void Pacman::initGameObject()
{
	setColor(Color::WHITE);
	setDirection(Nothing);
	score = 0;
	life = 3;
}

