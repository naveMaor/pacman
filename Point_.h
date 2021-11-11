#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils_.h"
#include <stdlib.h>

using namespace std;



class Point 
{
private:
		int x;
		int y; 

public:
	//constractor
	Point(int newX, int newY)
		:x(newX), y(newY) {};

	void		draw(char ch);
	void		move(int direction);
	void		randomMove();

	void		setX(int newX);
	int			getX() const;

	void		setY(int newY);
	int			getY() const;

};

#endif