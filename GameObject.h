#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Point.h"
#include "Board.h"
#include "MoveStrategy.h"

class GameObject
{
	// GameObject data members
	Color color = Color::WHITE;
	int direction = 3;
	Point pBody;
	char objectIcon;

protected:
	unsigned char lastboardval = 0;
public:
	GameObject(char objectIcon) : objectIcon(objectIcon){}
	// Constractor
	GameObject(int x, int y, char icon) : pBody(x, y), objectIcon(icon){};

	// GameObject functions
	void setBody(Point point);
	void setBody(int x, int y);
	Point getBody() const {	return pBody;};
	int getDirection() { return direction; }
	void setDirection(int direction);
	Color getColor() const { return color; };
	void setColor(Color color);
	void setObjectIcon(char icon) { objectIcon = icon; }
	char getObjectIcon() { return objectIcon; }

	void move(Board & b);
	void draw() const;
	virtual void initGameObject();
	void printBreadCrumbs(int x, int y);
	void changedirectionbyPoint(Point p);
	static bool checkValidPos(int x, int y, Board& b);
	static bool checkValidMove(int x, int y, int dir, Board &b);
	static void IlustrateNextMove(int& x, int& y, int dir, Board &b);
	void removeObject(Board& b);
	void MoveOfPacman();

};

#endif