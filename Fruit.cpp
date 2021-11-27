#include "Fruit.h"

void Fruit :: setNewDigit()
{
	char num = (char)rand() % 57 + 53;
	while (num == digit)
	{
		num = (char)rand() % 57 + 53;
	}
	digit = num;
}
char Fruit::getDigit() const
{
	return digit;
}


void Fruit::setFruitBody(Point newLocation)
{
	FruitBody = newLocation;
}