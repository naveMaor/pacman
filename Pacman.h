#pragma once
#include "Point.h"
#include "GameObject.h"

class Pacman : public GameObject
{
private:
	// Pacman data members
	/*Point pacmanBody;
	int direction = 4;
	Color color = Color::WHITE;*/

	int score = 0;
	int life = 3;
	

public:
	// Constractor
	Pacman(int x, int y): GameObject(x,y,pacmanIcon) {};

	//// Pacman functions
	//void move();
	//void draw() const;

	////Getters and setters
	//int getDirection() const;
	//void setDirection(int newDirection);
	//
	//Point getPacmanBody() const;
	//void setPacmanBody(int x, int y);
	//Color getColor() const { return this->getColor(); };
	//void setColor(Color color);


	int	getScore() const { return score; };
	void setScore(int x) { score = x; };
	void setPlusScore() { score++; }
	int	getLife() const { return life; };
	void setLife(int newLife) { life = newLife; };
	void initPacman();

};

