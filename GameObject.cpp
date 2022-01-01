#include "GameObject.h"

/* This function set the body of the gameobject at point*/
void GameObject::setBody(Point point)
{
	this-> pBody = point; // low copy
}

/* Thsi function set the body of gameobject at x and y*/
void GameObject::setBody(int x, int y)
{
	this->pBody.setX(x);
	this->pBody.setY(y);
}

/* This function set the direction of gameobject*/
void GameObject::setDirection(int direction)
{
	this->direction = direction;
}

/* This function set the color of gameobject*/
void GameObject::setColor(Color color)
{
	this->color = color;
}

// This function move the gameobject and delete the last place by space
void GameObject::move()
{
	pBody.draw(space);
	pBody.move(direction);
	draw();
}

/* This function draw the game object by his color at his current place*/
void GameObject::draw() const
{
	setTextColor(color);
	pBody.draw(objectIcon);
	setTextColor(Color:: WHITE);
}

/* This function init gameobject*/
void GameObject::initGameObject()
{
	setColor(Color::WHITE);
	setDirection(Stay);
}

/* This function ilustrate the next move*/
void GameObject::IlustrateNextMove(int& x, int& y, int dir)
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

char GameObject::directionToChar()
{
	switch (direction)
	{
	case 0: // LEFT
		return 'L';
		break;
	case 1: // RIGHT
		return 'R';
		break;
	case 2: // UP
		return 'U';
		break;
	case 3: // DOWN
		return 'D';
		break;
	case 4: // STAY
		return 'S';
		break;

	}
}

void GameObject::PushDirectionToVector(char dir)
{
	steps.push_back(dir);
}

///* This function print breadcrumbs at point*/
void GameObject::printBreadCrumbs(int x, int y)
{
	unsigned char breadCrumb = UTILITIES_H::breadCrumb;
	setTextColor(Color::WHITE);
	gotoxy(x, y);
	cout << breadCrumb;
}

///* This function check if next move is valid */
bool GameObject::checkValidMove(int x, int y, int dir, Board& b)
{
	IlustrateNextMove(x, y, dir);
	unsigned char charAtNextPoint = b.getBoardValFromPoint(x, y);

	// If the game object out of board
	if ((x == b.getBoardStartWidth()) || (x == b.getBoardWidth()) ||
		//(y == b.getBoardStartHight()) || (y == b.getBoardEndHight()))
		(y == b.getBoardStartHight()) || (y == b.getBoardHight()))
		return false;

	// If the next move is wall, tunnel or ghost this isn't valid move
	if ((charAtNextPoint == wall) || (charAtNextPoint == space) || 
		(charAtNextPoint == ghostIcon) || (charAtNextPoint == gameInfoArea))
		return false;

	return true;
}

/* This function check Valid position*/
bool GameObject::checkValidPos(int x, int y, Board& b)
{
	unsigned char charAtPoint = b.getBoardValFromPoint(x, y);
	if ((x <= b.getBoardStartWidth()) || (x >= b.getBoardWidth()) ||
		(y <= b.getBoardStartHight()) || (y >= b.getBoardEndHight()))
		return false;

	// If wall, tunnel or ghost this isn't valid move
	if ((charAtPoint == wall) || (charAtPoint == space) || (charAtPoint == ghostIcon) || (charAtPoint == gameInfoArea))
		return false;
	return true;
}

/* This function chande direction by point*/
void GameObject::changeDirectionByPoint(Point nextPoint)
{
	int bodyX = pBody.getX();
	int bodyY = pBody.getY();
	int nextPointX = nextPoint.getX();
	int nextPointY = nextPoint.getY();

	//	Go UP
	if (nextPointX < bodyX)
		setDirection(Left);

	//	Go Right
	else if (nextPointX > bodyX)
		setDirection(Right);

	//	Go Up
	else if (nextPointY < bodyY)
		setDirection(Up);

	//	Go Down
	else if (nextPointY > bodyY)
		setDirection(Down);
}

/* This function remove Object last character after pacman hit*/
void GameObject::removeObject(Board& b)
{
	int x = this->getBody().getX();
	int y = this->getBody().getY();
	gotoxy(x, y);
	if (b.getBoardValFromPoint(x, y) == breadCrumb)
	{
		setTextColor(Color::WHITE);
		printBreadCrumbs(x, y);
	}
	else
		cout << (char)space;
}

char getValueFromVector(vector<char>& v, int iteration)
{
	return v[iteration];
}