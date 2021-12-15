#pragma once
#include "Point.h"
#include "GameObject.h"



class Ghost : public GameObject
{
	// Ghost data members
	/*
	Point ghostBody;
	Color color = Color::WHITE;
	int direction = 3;
	*/

public:
	// Constractor
	Ghost();
	Ghost(int x, int y) : GameObject(x, y, ghostIcon){};
	void initGameObject() override;
	void changePosition(Board& b) override;
	void removeGhost(Board &b);



};

