#include "Ghost.h"

void Ghost::initGameObject () 
{
	this->setColor(Color::WHITE);
	this->setDirection(directions::Stay);
}


/* This function handle ghost hit*/
bool Ghost::ghostHit(Point Body)
{
	if (this->getBody() == Body)
		return true;
	return false;
}

/* This function chase after pacman*/
Point Ghost::minDistance(Point PlayerLocation, Board& board)
{
	{
		Point Pcurr(0, 0);
		QItem source(PlayerLocation.getX(), PlayerLocation.getY(), Pcurr);
		int Hight = board.getBoardEndHight();
		int Width = board.getBoardWidth();

		// To keep track of visited QItems. Marking
		// blocked cells as visited.
		bool visited[HIGHT][WIDTH] = { false };
		// init source
		source.row = PlayerLocation.getX();
		source.col = PlayerLocation.getY();

		// applying BFS on matrix cells starting from source
		std::queue<QItem> q;
		q.push(source);
		visited[source.col][source.row] = true;
		while (!q.empty())
		{
			QItem curr = q.front();
			q.pop();

			// Destination found;
			if (this->getBody().getX() == curr.row && this->getBody().getY() == curr.col)
				return curr.p;

			Pcurr.setX(curr.row);
			Pcurr.setY(curr.col);

			// moving right
			if (curr.row + 1 < Width && checkValidPos(curr.row + 1, curr.col, board) && visited[curr.col][curr.row + 1] == false)
			{
				q.push(QItem(curr.row + 1, curr.col, Pcurr));
				visited[curr.col][curr.row + 1] = true;
			}
			// moving down
			if (curr.col + 1 < Hight && checkValidPos(curr.row, curr.col + 1, board) && visited[curr.col + 1][curr.row] == false)
			{
				q.push(QItem(curr.row, curr.col + 1, Pcurr));
				visited[curr.col + 1][curr.row] = true;
			}

			// moving left
			if (curr.row - 1 >= 0 && checkValidPos(curr.row - 1, curr.col, board) && visited[curr.col][curr.row - 1] == false)
			{
				q.push(QItem(curr.row - 1, curr.col, Pcurr));
				visited[curr.col][curr.row - 1] = true;
			}

			// moving up
			if (curr.col - 1 >= 0 && checkValidPos(curr.row, curr.col - 1, board) && visited[curr.col - 1][curr.row] == false)
			{
				q.push(QItem(curr.row, curr.col - 1, Pcurr));
				visited[curr.col - 1][curr.row] = true;
			}
		}
		Point p1(-1, -1);
		return p1;
	}
}