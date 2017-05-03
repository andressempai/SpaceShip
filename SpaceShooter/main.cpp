#include <SFML\Graphics.hpp>
#include "Game.h"

int main()
{
	/* Custom Game Object */
	Game _spaceShooter;
	int sp_frameCounter = 0;

	/* Game Loop */
	while (!_spaceShooter.GetWindow()->IsDone())
	{
		++sp_frameCounter;
		_spaceShooter.HandleInput();
		_spaceShooter.Update(sp_frameCounter);
		_spaceShooter.Render();
		_spaceShooter.RestartClock();
	}

	return 0;
}