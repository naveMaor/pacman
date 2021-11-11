// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Point_.h"

//Point::Point(int _x, int _y) {
//	x = _x;
//	y = _y;
//}

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}

void Point::randomMove() {
	int dir = rand() % 4;
	move(dir);
}

void Point::move(int dir) {
	switch (dir) {
	case 0: // UP
		--y;
		if (y < 1) {
			y = 24;
		}
		break;
	case 1: // DOWN
		++y;
		if (y > 24) {
			y = 1;
		}
		break;
	case 2: // LEFT
		--x;
		if (x < 1) {
			x = 79;
		}
		break;
	case 3: // RIGHT
		++x;
		if (x > 79) {
			x = 1;
		}
		break;
	case 4: //Nothing
		
		break;
	}

}

void Point::setX(int newX)
{
	x = newX;
}

int Point::getX ()  const
{
	return x;
}

void Point::setY(int newY) 
{
	y = newY;
}

int Point::getY()  const
{
	return y;
}