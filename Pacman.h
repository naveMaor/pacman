#pragma once
#include "Point.h"

class Pacman
{
private:
	Point pacmanBody;
	int score = 0;
	int life = 3;
	int direction = 3;


public:
	//constractor
	Pacman(int newX, int newY):pacmanBody(newX, newY) {};
	//____________________________________________________________________________________________

	//Move pacman by class member - "direction"
	void			move();
	//____________________________________________________________________________________________

	//Getters and setters
	int				getDirection() const;
	void			setDirection(int newDirection);
	int			getScore() const { return score; };
	void			setScore() { score++; }

	int			getLife() const { return life; };
	void			setLife() { life--; }

	Point			getPacmanBody();
	//____________________________________________________________________________________________


};

