#include "Fruit.h"


void Fruit::setNewFruitScore()
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
	int newx = randomBetween(0, b.getBoardWidth() - 1);
	int newy = randomBetween(0, b.getBoardHight() - 1);
	bool valid = checkValidPos(newx, newy, b);
	while (!valid)
	{
		newx = randomBetween(0, b.getBoardWidth() - 1);
		newy = randomBetween(0, b.getBoardHight() - 1);
		valid = checkValidPos(newx, newy, b);
	}
	setBody(newx, newy);
}

/* This function handle Fruit move*/

void Fruit::changePosition(Board& b, int& countPacmanMoves)
{
	if (countPacmanMoves % 20 == 0)
	{
		this->setshowfruit();
		this->hideOrShowFruit(b);
		if (!this->getshowfruit())
		{
			this->setNewFruitScore();
		}
	}

	if (countPacmanMoves % 4 == 0 && showfruit)
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

}


void Fruit::hideOrShowFruit(Board& b)
{
	if (showfruit)
		this->draw();
	else
	{
		unsigned char c = b.getBoardValFromPoint(this->getBody().getX(), this->getBody().getY());
		gotoxy(this->getBody().getX(), this->getBody().getY());
		if (c == boardGarbageVal)
			cout << (char)space;
		else
			cout << c;
		setNewFruitlocation(b);
	}
}

//void Fruit::fruitPlay(int countMoves, Board& b)
//{
//	if (countMoves % 20 == 0)
//	{
//		this->setshowfruit();
//		this->hideOrShowFruit(b);
//			if (!this->getshowfruit())
//			{
//			this->setNewFruitScore();
//			}
//	}
//
//	if (countMoves % 4 == 0 && this->getshowfruit())
//	{
//		this->changePosition(b);
//	}
//}