#pragma once
#include "Point.h"

class Fruit
{
	Point FruitBody;
	char digit;


public:
	Fruit() : digit((char)rand() % 57 + 53) {}
	Fruit(int newX, int newY) : FruitBody(newX, newY), digit((char)rand() % 57 + 53) {}

	// Functions
	void move();

	void setFruitBody(Point newLocation);
	char getDigit() const;
	void setNewDigit();
};
