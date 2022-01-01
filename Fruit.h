#ifndef FRUIT_H
#define FRUIT_H
#include "Point.h"
#include "Board.h"
#include "GameObject.h"

class Fruit : public GameObject
{
	char fruitScore = defaltFruitIcon;
	bool showfruit = true;
	vector<char> isShow;
	vector<std::pair<char, char>> Location;

public:
	Fruit() : GameObject(defaltFruitIcon) {}
	Fruit(int x, int y) : GameObject(x, y, fruitScore) {
		fruitScore = randomBetween(53, 57);
		this->setObjectIcon(fruitScore);
	};

	// Functions
	int getFruitScore() const { return fruitScore-'0'; };
	bool getshowfruit() const { return showfruit; }
	void setNewFruitScore();
	void setNewFruitlocation(Board& b);
	void initFruit(Board& b);
	void changePosition(Board& b, int& countPacmanMoves); 
	void setshowfruit() { showfruit = (!showfruit); };
	void hideOrShowFruit(Board& b);
	int randomBetween(int min, int max);
	void PushLocationToVector(char first, char second);
	char getValueFromisShowVector(int iteration) const;
	std::pair<char, char> getValueFromLocationVector(int iteration) const;
};

#endif 