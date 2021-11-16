
#include "Point.h"


/* This function draw requested char in point*/
void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch;
}

/* This function change x or y by requested direction*/
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

/* This function get the x of point*/
int Point::getX ()  const
{
	return x;
}

/* This function get the y of point*/
int Point::getY()  const
{
	return y;
}

/* This freind function overloading == opeartor for point*/
bool operator== (const Point& pointOne, const Point& pointTwo)
{
	return ((pointOne.getX() == pointTwo.getX()) && (pointOne.getY() == pointTwo.getY()));
}
