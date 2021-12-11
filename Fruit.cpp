#include "Fruit.h"


void Fruit ::setNewFruitScore()
{
	char num = (char)rand() % 57 + 53;
	while (num == fruitScore)
	{
		num = (char)rand() % 57 + 53;
	}
	fruitScore = num;
	this->setObjectIcon(fruitScore);
}

void Fruit::initGameObject() {
	setColor(Color::WHITE);
	setDirection(Nothing);
}

void Fruit::initFruit(Board& b)
{
	setColor(Color::WHITE);
	setDirection(Nothing);
	setNewFruitlocation(b);
}

void Fruit::setNewFruitlocation(Board& b)
{
	int newx = rand() % (20 + 1);
	int newy = rand() % (70 + 1);
	char ch = b.getBoardValFromPoint(newx, newy);
	while (ch == characterEnum::w || ch== characterEnum::space)
	{
		newx = rand() % (20 + 1);
		newy = rand() % (70 + 1);
		ch = b.getBoardValFromPoint(newx, newy);
	}
	
}

/* This function handle Fruit move*/
void Fruit::changePosition(Board& b)
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
