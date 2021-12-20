#include "Fruit.h"

/* This functio nset fruit new score*/
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

/* This function init fruit*/
void Fruit::initFruit(Board& b)
{
	initGameObject();
	setNewFruitlocation(b);
}

/* This function set new fruit location*/
void Fruit::setNewFruitlocation(Board& b)
{
	int newX = randomBetween(b.getBoardStartWidth(), b.getBoardWidth());
	int newY = randomBetween(b.getBoardStartHight(), b.getBoardEndHight());
	bool valid = checkValidPos(newX, newY, b);

	while (!valid)
	{
		newX = randomBetween(b.getBoardStartWidth(), b.getBoardWidth());
		newY = randomBetween(b.getBoardStartHight(), b.getBoardEndHight());
		valid = checkValidPos(newX, newY, b);
	}
	setBody(newX, newY);
}

/* This function handle Fruit move*/
void Fruit::changePosition(Board& b, int& countPacmanMoves)
{
	if (countPacmanMoves % 20 == 0)
	{
		this->setshowfruit();
		this->hideOrShowFruit(b);
		if (!this->getshowfruit())
			this->setNewFruitScore();
		
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
		if (b.getBoardValFromPoint(x, y) == breadCrumb)
			printBreadCrumbs(x, y);
	}
}

/* This function hid or show the fruit on the screen*/
void Fruit::hideOrShowFruit(Board& b)
{
	if (showfruit)
		this->draw();
	else
	{
		unsigned char c = b.getBoardValFromPoint(this->getBody().getX(), this->getBody().getY());
		gotoxy(this->getBody().getX(), this->getBody().getY());
		setTextColor(Color::WHITE);
		if (c == boardGarbageVal)
			cout << (char)space;
		else
			cout << c;
		setNewFruitlocation(b);
	}
}

/* This function get random between two numbers*/
int Fruit::randomBetween(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}