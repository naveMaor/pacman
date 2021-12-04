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



