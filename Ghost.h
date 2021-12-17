#ifndef GHOST_H
#define GHOST_H
#include "Point.h"
#include "GameObject.h"
#include "MoveStrategy.h"
#include <queue>

struct  QItem {
public:
	int row;
	int col;
	Point p;
	QItem(int x, int y, Point p)
		: row(x), col(y), p(p)
	{}
};

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
	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) = 0;
	void removeGhost(Board &b);
	bool ghostHit(Point Body);
	Point minDistance(Point PlayerLocation, Board& board);

};

#endif