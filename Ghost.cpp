
#include "Ghost.h"

/* This function remove ghost from board and draw it in the new place by direction*/
void Ghost::move() 
{
	ghostBody.draw(space);
	ghostBody.move(direction);
	draw();
}

/* This function draw the ghost in current location*/
void Ghost::draw()
{
	setTextColor(color);
	ghostBody.draw(ghostIcon);
}

/* This function get x,y and set it to ghost*/
void Ghost::setGhostBody(int newX, int newY)
{
	ghostBody.setX(newX);
	ghostBody.setY(newY);
}

/* This function return ghost Point (x,y)*/
Point Ghost::getGhostBody() const
{
	return ghostBody;
}

/* This function set ghost direction*/
void Ghost::setGhostDirection(int direction)
{
	this->direction = direction;
}

/* This function change ghost color*/
void Ghost::setColor(Color color)
{
	this->color = color;
}

/* This function init ghost*/
void Ghost:: initGhost()
{
	this->color = Color::WHITE;
	this->direction = 3;
}

