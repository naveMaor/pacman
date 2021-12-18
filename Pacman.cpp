#include "Pacman.h"

void Pacman::initGameObject()
{
	this->life = 3;
	this->setColor(Color::WHITE);
	this->setDirection(Stay);
}

bool Pacman::isValidMove(Board& b)
{
	Point nextPos = this->getBody();// current location
	nextPos.move(this->getDirection());
	unsigned char charAtnextPoint = b.getBoardValFromPoint(nextPos.getX(), nextPos.getY());
	int x = nextPos.getX(), y = nextPos.getY(), width = b.getBoardStartWidth(), hight = b.getBoardStartHight();

	// if next move is wall return false
	if ((charAtnextPoint == wall)|| charAtnextPoint == gameInfoArea)
		return false;

	if (y == hight && b.getBoardValFromPoint(x, 0) != wall && b.getBoardValFromPoint(x, 0) != gameInfoArea)

	else if (y <= hight && y >= -1)
	{
		if (y == hight && b.getBoardValFromPoint(x, 0) != wall && b.getBoardValFromPoint(x, 0) != gameInfoArea)
			return true;
		else if (y == -1 && b.getBoardValFromPoint(x, hight - 1) != wall)
			return true;
		else
			return true;
	}
		
	else if (x < wall && x > 0)
		return true;
	

}

void Pacman::changePosition(Board& b, int& countPacmanMoves)
{
	int x = this->getBody().getX();
	int y = this->getBody().getY();

	Point nextPos = this->getBody();
	nextPos.move(this->getDirection());
	unsigned char charAtPoint = b.getBoardValFromPoint(x, y);
	unsigned char charAtnextPoint = b.getBoardValFromPoint(nextPos.getX(), nextPos.getY());


	if (b.getBoardValFromPoint(x, y) == breadCrumb)
	{
		score++;
		b.eatBreadCrumb();
		b.setBoardValByPoint(x, y); // sign we was here
	}
	
	if (isValidMove(b))
	{
		if (isTunnel())
			moveTunnel()
		else
			this->move();
	}
	









	
		// If player is going through tunnel
		//if (charAtnextPoint == space)
		//{
			if (charAtPoint == breadCrumb) // if there was at curr pos then raise score
			{
				this->setPlusScore();
				b.eatBreadCrumb();
				b.setBoardValByPoint(x, y);
			}

			if (x == 0) {
				this->getBody().draw(space);
				this->setBody(b.getBoardWidth() - 1, y);
			}

			else if (x == b.getBoardWidth() - 1) {
				this->getBody().draw(space);
				this->setBody(0, y);
			}
			else if (y == 0)
			{
				this->getBody().draw(space);
				this->setBody(x, b.getBoardHight() - 1);
			}
			else if (y == b.getBoardHight() - 1)
			{
				this->getBody().draw(space);
				this->setBody(x, 0);
			}
			//this->move();
		//}
		//else
			if (charAtnextPoint == wall)
				this->setDirection(4);

		else
		{
			// if there breadcrumb
			if (charAtPoint == breadCrumb)
			{
				b.eatBreadCrumb();
				this->setPlusScore();
			}
			b.setBoardValByPoint(x, y);
			this->move();
		}
		countPacmanMoves++;
	//}
}

/* This function remove pacman last character*/
void Pacman::remove()
{
	gotoxy(this->getBody().getX(), this->getBody().getY());
	cout << (char)space;
}
