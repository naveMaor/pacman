#include "Fruit.h"


void Fruit ::setNewFruitScore()
{
	char num = randomBetween(53, 57);
	while (num == fruitScore)
	{
		num = randomBetween(53, 57);
	}
	fruitScore = num;
	this->setObjectIcon(fruitScore);
}


void Fruit::initFruit(Board& b)
{
	initGameObject();
	setNewFruitlocation(b);
}

void Fruit::setNewFruitlocation(Board& b)
{
	int newx = randomBetween(0, HIGHT);
	int newy = randomBetween(0, WIDTH);
	char ch = b.getBoardValFromPoint(newx, newy);
	while (ch == characterEnum::w || ch== characterEnum::space)
	{
		newx = randomBetween(0, HIGHT);
		newy = randomBetween(0, WIDTH);
		ch = b.getBoardValFromPoint(newx, newy);
	}
	
}

/* This function handle Fruit move*/
void Fruit::changePosition(Board& b)
{
	int x = this->getBody().getX();
	int y = this->getBody().getY();
	int direction = randomBetween(0, 4);

	// If wall get new random direction
	while (!checkValidMove(x, y, direction, b))
		direction = randomBetween(0, 4);

	this->setDirection(direction);
	this->move();

	// If last ghost position was breadcrumb print breadcrumb
	if (b.getBoardValFromPoint(x, y) == bc)
		printBreadCrumbs(x, y);
}

void Fruit::hideshowFruit(bool showfruit,Board &b)
{
	if (showfruit)
	{
		setNewFruitlocation(b);
		draw();
	}

	else
	{
		unsigned char c = b.getBoardValFromPoint(getBody().getX(), getBody().getY());
		if (c == boardGarbageVal)
		{
			gotoxy(getBody().getX(), getBody().getY());
			cout << (char)space;
		}
		else
		{
			gotoxy(getBody().getX(), getBody().getY());
			cout << c;
		}
	}
}