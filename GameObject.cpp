#include "GameObject.h"


void GameObject::move()
{
	pBody.draw(space);
	pBody.move(direction);
	draw();
}

void GameObject::draw() const
{
	setTextColor(color);
	pBody.draw(gameObjIcon);
}

void GameObject::setBody(int x, int y)
{
	pBody.setX(x);
	pBody.setY(y);
}

Point GameObject::getBody() const
{
	return pBody;
}

void GameObject::setDirection(int direction)
{
	direction = direction;
}

void GameObject::setColor(Color color)
{
	color = color;
}

void GameObject::initGameObject()
{
	this->color = Color::WHITE;
	this->direction = 4;
}