#pragma once
#include "Point.h"
#include "GameObject.h"

class Fruit : public GameObject
{
	Point fruitBody;
	char fruitScore = defaltFruitIcon;


public:
	Fruit(int x, int y) : GameObject(x, y, fruitScore) {
		fruitScore = (char)rand() % 57 + 53;
		this->setObjectIcon(fruitScore);
	};

	// Functions
	char getFruitScore() const { return fruitScore; };
	void setNewFruitScore();
};
