#include "GoodGhost.h"


void::GoodGhost::changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation)
{
	if (countPacmanMoves % 3 == 0)
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
			move(b);
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
				move(b);
			}
		}

	}


}