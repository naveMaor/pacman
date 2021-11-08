#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils_.h"

using namespace std;



class Point {
	int x = 39, y = 12;
public:
	void draw(char ch);
	void move(int direction);
};

#endif