#pragma once
#include "Point.h"
#include "Board.h"

class GameObject
{
	// GameObject data members
	Point pBody;
	Color color = Color::WHITE;
	char objectIcon;
	int direction = 3;

public:
	// Constractor
	GameObject(int x, int y, char icon) : pBody(x, y), objectIcon(icon) {};

	// GameObject functions
	void setBody(int x, int y);
	Point getBody() const {	return pBody;};
	int getDirection() { return direction; }
	void setDirection(int direction);
	Color getColor() const { return color; };
	void setColor(Color color);
	void setObjectIcon(char icon) { objectIcon = icon; }
	char getObjectIcon() { return objectIcon; }

	void move();
	void draw() const;
	virtual void initGameObject();
	virtual void changePosition(Board& b) =0;
	bool checkValidMove(int x, int y, int dir, Board &b);
	void IlustrateNextMove(int& x, int& y, int dir, Board &b);
	void printBreadCrumbs(int x, int y);
	
};

