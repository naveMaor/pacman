#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "Utilities.h"
#include <stdlib.h>


using std::cout;

class Point 
{
private:
		int x = 1, y = 1;

public:
	//constractor
	Point(int newX, int newY) : x(newX), y(newY) {};

	void draw(char ch);
	void move(int direction);
	void setX(int newX) { x = newX; }
	int	getX() const;
	void setY(int newY) { y = newY; }
	int	getY() const;
	friend bool operator== (const Point& pointOne, const Point& pointTwo);
};

#endif