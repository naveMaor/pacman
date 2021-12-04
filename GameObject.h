#pragma once
#include "Point.h"

class GameObject
{
	// Ghost data members
	Point pBody;
	Color color = Color::WHITE;
	char gameObjIcon;
	int direction = 3;

public:
	// Constractor
	GameObject();
	GameObject(int x, int y, char icon) : pBody(x, y), gameObjIcon(icon) {};

	// Ghost functions
	void setBody(int x, int y);
	Point getBody() const;
	int getDirection() { return direction; }
	void setDirection(int direction);
	Color getColor() const { return color; };
	void setColor(Color color);
	void setObjIcon(char icon) { gameObjIcon = icon; }
	char getObjIcon() { return gameObjIcon; }

	void move();
	void draw() const;
	void initGameObject();
	
};

