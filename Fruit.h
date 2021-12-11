#pragma once
#include "Point.h"
#include "Board.h"
#include "GameObject.h"

class Fruit : public GameObject
{
	char fruitScore = defaltFruitIcon;

public:
	Fruit(int x, int y) : GameObject(x, y, fruitScore) {
		fruitScore = randomBetween(53, 57);
		this->setObjectIcon(fruitScore);
	};

	// Functions
	char getFruitScore() const { return fruitScore; };
	void setNewFruitScore();
	void setNewFruitlocation(Board& b);
	void initFruit(Board& b);
	void changePosition(Board& b) override;
	void hideshowFruit(bool showfruit, Board& b);

};
