#include "GameObject.h"

void GameObject::setBody(Point point)
{
	this-> pBody = point; // low copy
	/*pBody.setX(point.getX());
	pBody.setY(point.getX());*/
}

void GameObject::setBody(int x, int y)
{
	this->pBody.setX(x);
	this->pBody.setY(y);
}


void GameObject::setDirection(int direction)
{
	this->direction = direction;
}

void GameObject::setColor(Color color)
{
	this->color = color;
}
//todo: fix balagan
void GameObject::move()
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
	if ((x == b.getBoardWidth()) || (x == 0) || (y == 0) || (y == b.getBoardHight()))
		return false;

	// If the next move is wall, tunnel or ghost this isn't valid move
	if ((charAtNextPoint == w) || (charAtNextPoint == space) || (charAtNextPoint == ghostIcon))
		return false;

	return true;
}

bool GameObject::checkValidPos(int x, int y, Board& b)
{
	unsigned char charAtPoint = b.getBoardValFromPoint(x, y);
	if ((x == b.getBoardWidth()) || (x == 0) || (y == 0) || (y == b.getBoardHight()))
		return false;

	// If wall, tunnel or ghost this isn't valid move
	if ((charAtPoint == w) || (charAtPoint == space) || (charAtPoint == ghostIcon) || ((charAtPoint>=53) && (charAtPoint <=57)))
		return false;

	return true;
}

void GameObject::changedirectionbyPoint(Point NewP)
{
	int Bodyx = pBody.getX();
	int Bodyy = pBody.getY();
	int NewPx = NewP.getX();
	int NewPy = NewP.getY();

//	Go UP
	if (NewPx < Bodyx)
		setDirection(Left);

//	Go Right
	else if (NewPx > Bodyx)
		setDirection(Right);

//	Go Up
	else if (NewPy < Bodyy)
		setDirection(Up);

	//	Go Down
	else if (NewPy > Bodyy)
		setDirection(Down);
}