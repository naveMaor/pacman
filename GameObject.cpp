#include "GameObject.h"

void GameObject::setBody(Point point)
{
	pBody = point; // low copy
}

void GameObject::setBody(int x, int y)
{
	pBody.setX(x);
	pBody.setY(y);
}


void GameObject::setDirection(int direction)
{
	this->direction = direction;
}

void GameObject::setColor(Color color)
{
	this->color = color;
}

void GameObject::move()
{
	pBody.draw(space);
	pBody.move(direction);
	draw();
}


void GameObject::moveAndDraw()
{
	pBody.draw(space);
	pBody.move(direction);
	draw();
}

void GameObject::draw() const
{
	setTextColor(color);
	pBody.draw(objectIcon);
}
void GameObject::initGameObject()
{
	setColor(Color::WHITE);
	setDirection(Stay);
}

///* This function ilustrate the next move*/
void GameObject::IlustrateNextMove(int& x, int& y, int dir, Board& b)
{
	switch (dir)
	{
	case 0: // LEFT
		x--;
		break;
	case 1: // RIGHT
		x++;
		break;
	case 2: // UP
		y--;
		break;
	case 3: // DOWN
		y++;
		break;
	}

}

///* This function print breadcrumbs at point*/
void GameObject::printBreadCrumbs(int x, int y)
{
	unsigned char breadCrumb = bc;
	setTextColor(Color::WHITE);
	gotoxy(x, y);
	cout << breadCrumb;
}

///* This function check if next move is valid */
bool GameObject::checkValidMove(int x, int y, int dir, Board& b)
{
	IlustrateNextMove(x, y, dir, b);
	unsigned char charAtNextPoint = b.getBoardValFromPoint(x, y);

	// If the ghost out of board
	if ((x == 69) || (x == 0) || (y == 0) || (y == 19))
		return false;

	// If the next move is wall, tunnel or ghost this isn't valid move
	if ((charAtNextPoint == w) || (charAtNextPoint == space) || (charAtNextPoint == ghostIcon))
		return false;

	return true;
}

bool GameObject::checkValidPos(int x, int y, Board& b)
{
	unsigned char charAtPoint = b.getBoardValFromPoint(x, y);
	if ((x == 69) || (x == 0) || (y == 0) || (y == 19))
		return false;

	// If the next move is wall, tunnel or ghost this isn't valid move
	if ((charAtPoint == w) || (charAtPoint == space) || (charAtPoint == ghostIcon))
		return false;

	return true;

}

