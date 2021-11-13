#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils_.h"
#include <stdlib.h>
#include "io_utils_.h"

using namespace std;


class Point 
{
private:
		int x = 1, y = 1;

public:
	//constractor
	Point(int newX, int newY) : x(newX), y(newY) {};

	void		draw(char ch);
	void		move(int direction);

	void		setX(int newX) { x = newX; }
	int			getX() const;

	void		setY(int newY) { y = newY; }
	int			getY() const;
	bool operator == (const Point &point);
	

};

#endif