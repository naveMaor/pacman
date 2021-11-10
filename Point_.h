#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils_.h"
#include <stdlib.h>

using namespace std;



class Point {
	int x = 39, y = 12;

public:
	Point(int x, int y);
	void draw(char ch);
	void move(int direction);
	void randomMove();
	void setX(int x);
	void setY(int y);
};

#endif