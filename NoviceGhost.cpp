#include "NoviceGhost.h"

void NoviceGhost::changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation)
{
	if (countPacmanMoves % 3 == 0)
	{
		int x = getBody().getX();
		int y = getBody().getY();
		int direction = getDirection();
		bool validMove = checkValidMove(x, y, direction, b);
		if (countPacmanMoves % 20 == 0 || (!validMove))
		{
			direction = rand() % 4;

			// If not valid get new random direction
			while (!checkValidMove(x, y, direction, b))
				direction = rand() % 4;
			this->setDirection(direction);
		}
		move();

		// If last ghost position was breadcrumb print breadcrumb
		if (b.getBoardValFromPoint(x, y) == bc)
		{
			setTextColor(Color::WHITE);
			printBreadCrumbs(x, y);
		}
	}

	
}
