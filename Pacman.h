#ifndef PACMAN_H
#define PACMAN_H
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
	Pacman() : GameObject(pacmanIcon) {}
	Pacman(int x, int y): GameObject(x,y,pacmanIcon) {};
	void initGameObject() override;

	int	getScore() const { return score; };
	void setScore(int x) { score = x; };
	void setPlusScore() { score++; }
	int	getLife() const { return life; };
	void setLife(int newLife) { life = newLife; };
	void remove();
	void changePosition(Board& b, int& countPacmanMoves);
	void moveTunnel(Board& b);

	bool isTunnel(Board& b);
	bool isValidMove(Board& b);
};

#endif