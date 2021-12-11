#include "Pacman.h"

void Pacman::initGameObject()
{
	this->setColor(Color::WHITE);
	this->setDirection(Nothing);
	score = 0;
	life = 3;
}

