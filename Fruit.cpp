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
	int newx = randomBetween(0, b.getBoardWidth());
	int newy = randomBetween(0, b.getBoardHight());
	bool valid = checkValidPos(newx, newy, b);
	while (!valid)
	{
		newx = randomBetween(0, b.getBoardWidth());
		newy = randomBetween(0, b.getBoardHight());
		valid = checkValidPos(newx, newy, b);
	}
	setBody(newx, newy);
}

/* This function handle Fruit move*/

void Fruit::changePosition(Board& b, int& countPacmanMoves)
{
	if (countPacmanMoves % 20 == 0)
	{
		setshowfruit();
		hideOrShowFruit(b);
		if (!showfruit)
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
		this->move(b);
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
		setTextColor(Color::WHITE);
		if (c != ghostIcon)
		{
			if (c == boardGarbageVal)
				cout << (char)space;
			else
				cout << c;
		}
		setNewFruitlocation(b);
	}
}

