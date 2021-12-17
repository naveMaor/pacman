#include "GoodGhost.h"


void::GoodGhost::changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation)
{
	int x = this->getBody().getX();
	int y = this->getBody().getY();
	int direction = getDirection();
	if (countPacmanMoves % 20 >= 0 && countPacmanMoves % 20 <= 5)
	{
		if (countPacmanMoves % 20 == 0)
		{
			direction = rand() % 4;
		}

		// If not valid get new random direction
		while (!checkValidMove(x, y, direction, b))
			direction = rand() % 4;
		this->setDirection(direction);
		move();
		// If last ghost position was breadcrumb print breadcrumb
		if (b.getBoardValFromPoint(x, y) == bc)
			printBreadCrumbs(x, y);
	}
	else
	{
		Point newPoint = minDistance(PlayerLocation, b);
		Point tmp(-1, -1);
		int x = getBody().getX();
		int y = getBody().getY();
		if (newPoint == tmp)
		{

		}
		else
		{
			changedirectionbyPoint(newPoint);
			move();
			// If last ghost position was breadcrumb print breadcrumb
			if (b.getBoardValFromPoint(x, y) == bc)
				printBreadCrumbs(x, y);
		}
	}


}