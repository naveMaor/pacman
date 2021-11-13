// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Point.h"

//Point::Point(int _x, int _y) {
//	x = _x;
//	y = _y;
//}

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch;
}

void Point::move(int dir) {
	switch (dir) {
	case 0: // LEFT
		--x;

		break;
	case 1: // RIGHT
		++x;

		break;
	case 2: // UP
		--y;

		break;
	case 3: // DOWN
		++y;
		break;
	case 4: //Nothing

		break;
	}
}


int Point::getX ()  const
{
	return x;
}

int Point::getY()  const
{
	return y;
}

bool Point:: operator == (const Point& point)
{
	if ((this->x == point.x) && (this->y == point.y))
		return true;
	return false;
}
