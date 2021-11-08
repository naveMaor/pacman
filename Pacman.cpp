#include "Pacman.h"


void Pacman::move()
{
	body.draw(' ');
	body.move(direction);
	body.draw('@');


}

