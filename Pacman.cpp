#include "Pacman.h"

void Pacman::initGameObject()
{
	this->setColor(Color::WHITE);
	this->setDirection(Stay);
	score = 0;
	life = 3;
}

void Pacman::changePosition(Board& b)
{
	int x = this->getBody().getX();
	int y = this->getBody().getY();

	Point nextPos = this->getBody();
	nextPos.move(this->getDirection());


	unsigned char charAtnextPoint = b.getBoardValFromPoint(nextPos.getX(), nextPos.getY());
	unsigned char charAtPoint = b.getBoardValFromPoint(x, y);

	// If player is going through tunnel
	if (charAtnextPoint == space)
	{
		if (charAtPoint == bc) // if there was at curr pos then raise score
		{
			this->setPlusScore();
			b.setBoardValByPoint(x, y);
		}

		if (x == 1) {
			this->getBody().draw(space);
			this->setBody(69, y);
		}

		else if (x == 68) {
			this->getBody().draw(space);
			this->setBody(0, y);
		}
		else if (y == 1)
		{
			this->getBody().draw(space);
			this->setBody(x, 19);
		}
		else if (y == 18)
		{
			this->getBody().draw(space);
			this->setBody(x, 0);
		}
		this->moveAndDraw();
	}

	// if there is wall in the next move
	else if (charAtnextPoint == w)
		this->setDirection(4);

	else
	{
		// if there breadcrumb
		if (charAtPoint == bc)
		{
			this->setPlusScore();
		}
		b.setBoardValByPoint(x, y);
		this->moveAndDraw();
	}

}

/* This function remove pacman last character*/
void Pacman::remove()
{
	gotoxy(this->getBody().getX(), this->getBody().getY());
	cout << (char)space;
}
