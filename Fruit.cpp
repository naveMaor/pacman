#include "Fruit.h"

/* This fruit constructor*/
Fruit::Fruit(int x, int y) : GameObject(x, y, fruitScore)
{
	fruitScore = (char)rand() % 57 + 53;
	this->setObjectIcon(fruitScore);
}

void Fruit ::setNewFruitScore()
{
	char num = (char)rand() % 57 + 53;
	while (num == fruitScore)
	{
		num = (char)rand() % 57 + 53;
	}
	fruitScore = num;
}



