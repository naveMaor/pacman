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

	// Ghost functions
	/*void move();
	void draw() const;
	void setGhostBody(int newX, int newY);
	Point getGhostBody() const;
	void setGhostDirection(int direction);
	Color getColor() const { return this->getColor(); };
	void setColor(Color color);
	void initGhost();*/
};

