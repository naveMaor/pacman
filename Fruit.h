#pragma once
#include "Point.h"
#include "GameObject.h"

class Fruit : public GameObject
{
	Point fruitBody;
	char fruitScore = defaltFruitIcon;


public:
	Fruit(int x, int y);

	// Functions
	char getFruitScore() const { return fruitScore; };
	void setNewFruitScore();
};
