#ifndef GHOST_H
#define GHOST_H
#include "Point.h"
#include "GameObject.h"
#include "MoveStrategy.h"

class Ghost : public GameObject
{

public:
	// Constractor
	Ghost() : GameObject(ghostIcon) {}
	Ghost(int x, int y) : GameObject(x, y, ghostIcon){};
	void initGameObject() override;
	void changePosition(Board& b);
	void removeGhost(Board &b);
};

#endif