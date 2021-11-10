// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Board.h"
#include "Pacman.h"



int main()
{
	Board b;
	b.printBoard();

	Pacman p;
	p.setPacmanBody(10, 15);

	return 0;
}