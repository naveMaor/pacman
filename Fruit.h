#pragma once
#include "Point.h"
#include "Board.h"
#include "GameObject.h"

class Fruit : public GameObject
{
	char fruitScore = defaltFruitIcon;

public:
	Fruit(int x, int y) : GameObject(x, y, fruitScore) {
		fruitScore = (char)rand() % 57 + 53;
		this->setObjectIcon(fruitScore);
	};

	// Functions
	char getFruitScore() const { return fruitScore; };
	void setNewFruitScore();
	void initGameObject() override;
	void setNewFruitlocation(Board& b);
	void initFruit(Board& b);
	void changePosition(Board& b) override;


};
