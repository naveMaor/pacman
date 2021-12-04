#pragma once
#include "Point.h"

class GameObject
{
	// Ghost data members
	Point pBody;
	Color color = Color::WHITE;
	char objectIcon;
	int direction = 3;

public:
	// Constractor
	GameObject(int x, int y, char icon) : pBody(x, y), objectIcon(icon) {};

	// Ghost functions
	void setBody(int x, int y);
	Point getBody() const;
	int getDirection() { return direction; }
	void setDirection(int direction);
	Color getColor() const { return color; };
	void setColor(Color color);
	void setObjectIcon(char icon) { objectIcon = icon; }
	char getObjectIcon() { return objectIcon; }

	void move();
	void draw() const;
	void initGameObject();
	
};

