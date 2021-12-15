#ifndef GHOST_H
#define GHOST_H
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
	Ghost() : GameObject(ghostIcon) {}
	Ghost(int x, int y) : GameObject(x, y, ghostIcon){};
	void initGameObject() override;
	void changePosition(Board& b) override;
	void removeGhost(Board &b);



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

#endif