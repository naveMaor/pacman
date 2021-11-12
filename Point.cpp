// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Point.h"

//Point::Point(int _x, int _y) {
//	x = _x;
//	y = _y;
//}

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}



void Point::move(int dir) {
	switch (dir) {
	case 0: // LEFT
		--x;
		if (x < 1) {
			x = 69;
		}
		break;
	case 1: // RIGHT
		++x;
		if (x > 69) {
			x = 1;
		}
		break;
	case 2: // UP
		--y;
		if (y < 1) {
			y = 19;
		}
		break;
	case 3: // DOWN
		++y;
		if (y > 20) {
			y = 1;
		}
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