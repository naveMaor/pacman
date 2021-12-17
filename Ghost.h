#ifndef GHOST_H
#define GHOST_H
#include "Point.h"
#include "GameObject.h"
#include "MoveStrategy.h"



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



};

#endif