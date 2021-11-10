#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Board
{
	enum {WIDTH = 82, HIGHT = 25};
	char map[HIGHT][WIDTH];

public:
	Board() {};
	void buildBoard();
	void printBoard();
};

