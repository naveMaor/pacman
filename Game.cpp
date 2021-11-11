#include "Game.h"



bool Game::PacmanHitGhost(Ghost g1, Pacman player)
{
	Point Ppacman = player.getPacmanBody();
	Point Pghost = g1.getGhostBody();

	if (Ppacman.getX() == Pghost.getX() && Ppacman.getY() == Pghost.getY())
	{
		return true;
	}

	return false;
}