#pragma once

#include "Point_.h"




class Pacman
{
private:
	Point body;
	int direction = 3;

	enum myenum1 { a, w, d, x, s };
	enum myenum1 { A, W, D, X, S };


public:
	void move();
	const void getdirection();
	void setdirection(int direction);

};

