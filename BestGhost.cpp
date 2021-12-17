#include "BestGhost.h"


void::BestGhost::changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation)
{
	if (countPacmanMoves % 3 == 0)
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
