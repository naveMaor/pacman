#ifndef FRUIT_H
#define FRUIT_H
#include "Point.h"
#include "Board.h"
#include "GameObject.h"

class Fruit : public GameObject
{
	char fruitScore = defaltFruitIcon;
	bool showfruit = true;

public:
	Fruit() : GameObject(defaltFruitIcon) {}
	Fruit(int x, int y) : GameObject(x, y, fruitScore) {
		fruitScore = randomBetween(53, 57);
		this->setObjectIcon(fruitScore);
	};

	// Functions
	char getFruitScore() const { return fruitScore; };
	bool getshowfruit() const { return showfruit; }
	void setNewFruitScore();
	void setNewFruitlocation(Board& b);
	void initFruit(Board& b);
	void changePosition(Board& b) override;
	void setshowfruit() { showfruit = (!showfruit); };

};

#endif 