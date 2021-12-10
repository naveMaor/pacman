#include "GameObject.h"

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

void GameObject::draw() const
{
	setTextColor(color);
	pBody.draw(objectIcon);
}



