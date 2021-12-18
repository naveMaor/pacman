#include "Pacman.h"

void Pacman::initGameObject()
{
	this->life = 3;
	this->setColor(Color::WHITE);
	this->setDirection(Stay);
}

bool Pacman::isValidMove(Board& b)
{
	Point nextPos = this->getBody(); // current location
	nextPos.move(this->getDirection()); // next location
	unsigned char charAtnextPoint = b.getBoardValFromPoint(nextPos.getX(), nextPos.getY());
	int x = nextPos.getX(), y = nextPos.getY(), width = b.getBoardWidth(), hight = b.getBoardEndHight() + 1;
	int startBoardX = b.getBoardStartWidth() - 1, startBoardY = b.getBoardStartHight() - 1;

	// if next move is wall or game info area return false
	if ((charAtnextPoint == wall)|| charAtnextPoint == gameInfoArea)
		return false;

	// if out of board bounds
	else if (y < startBoardY || y > hight || x < startBoardX || x > width)
		return false;

	return true;
}

void Pacman::changePosition(Board& b, int& countPacmanMoves)
{
	int x = this->getBody().getX();
	int y = this->getBody().getY();
	
	unsigned char currentLocation = b.getBoardValFromPoint(x, y);

	if (currentLocation == breadCrumb)
	{
		score++;
		b.eatBreadCrumb();
		b.setBoardValByPoint(x, y); // sign we was here
	}
	
	if (isValidMove(b))
	{
		if (isTunnel(b))
			moveTunnel(b);
		else
			move();
	}
	countPacmanMoves++;
}

/* This function remove pacman last character*/
void Pacman::remove()
{
	gotoxy(this->getBody().getX(), this->getBody().getY());
	cout << (char)space;
}

bool Pacman::isTunnel(Board &b)
{
	Point nextPos = this->getBody(); // current location
	nextPos.move(this->getDirection()); // next location
	unsigned char charAtnextPoint = b.getBoardValFromPoint(nextPos.getX(), nextPos.getY());
	int x = nextPos.getX(), y = nextPos.getY(), width = b.getBoardWidth(), hight = b.getBoardEndHight() + 1;
	int startBoardX = b.getBoardStartWidth() - 1, startBoardY = b.getBoardStartHight() - 1;

	// if top tunnel
	if (y == startBoardY)
		if (b.getBoardValFromPoint(x, hight - 1) != wall && b.getBoardValFromPoint(x, hight - 1) != gameInfoArea)
			return true;
	if(y == hight)
		if (b.getBoardValFromPoint(x, startBoardY + 1) != wall && b.getBoardValFromPoint(x, startBoardY + 1) != gameInfoArea)
			return true;
	if(x == startBoardX)
		if (b.getBoardValFromPoint(width - 1, y) != wall && b.getBoardValFromPoint(width - 1, y) != gameInfoArea)
			return true;
	if (x == width)
		if (b.getBoardValFromPoint(startBoardX, y) != wall && b.getBoardValFromPoint(startBoardX, y) != gameInfoArea)
			return true;
	return false;
}

void Pacman::moveTunnel(Board& b)
{
	int highest = b.getBoardStartHight();
	int Lowest = b.getBoardHight() - 1;
	int mostLeft = b.getBoardStartWidth();
	int mostRight = b.getBoardWidth() - 1;

	if (highest == getBody().getY())
	{
		getBody().draw(space);
		setBody(getBody().getX(), Lowest);
		draw();
	}
	else if (Lowest == getBody().getY())
	{
		getBody().draw(space);
		setBody(getBody().getX(), highest);
		draw();
	}
	else if (mostLeft == getBody().getX())
	{
		getBody().draw(space);
		setBody(mostRight, getBody().getY());
		draw();
	}
	else if (mostRight == getBody().getX())
	{
		getBody().draw(space);
		setBody(mostLeft, getBody().getY());
		draw();
	}
}
