#include "Ghost.h"

void Ghost::initGameObject () 
{
	this->setColor(Color::WHITE);
	this->setDirection(Nothing);
}

void Ghost::changePosition(Board& b)
{
	int x = this->getBody().getX();
	int y = this->getBody().getY();
	int direction = rand() % 4;

	// If wall get new random direction
	while (!checkValidMove(x, y, direction, b))
		direction = rand() % 4;

	this->setDirection(direction);
	this->move();

	// If last ghost position was breadcrumb print breadcrumb
	if (b.getBoardValFromPoint(x, y) == bc)
		printBreadCrumbs(x, y);
}


void Ghost::removeGhost(Board& b)
{
	int x = this->getBody().getX();
	int y = this->getBody().getY();
	gotoxy(x, y);
	if (b.getBoardValFromPoint(x, y) == bc)
		printBreadCrumbs(x, y);
	else
		cout << (char)space;

}