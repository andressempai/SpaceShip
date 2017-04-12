#include <SFML\Graphics.hpp>
#include "Game.h"

int main()
{
	/* Custom Game Object */
	Game _spaceShooter;

	/* Game Loop */
	while (!_spaceShooter.GetWindow()->IsDone())
	{
		_spaceShooter.HandleInput();
		_spaceShooter.Update();
		_spaceShooter.Render();
		_spaceShooter.RestartClock();
	}

	return 0;
}