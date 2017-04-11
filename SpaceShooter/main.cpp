#include <SFML\Graphics.hpp>
#include <algorithm>
#include <list>
#include "Game.h"
#include "Bullet.h"

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

/*
for (std::list<Bullet*>::iterator Aiter = _bullets.begin(); Aiter != _bullets.end(); ++Aiter)
{
	(*Aiter)->SetVelocity(BulletVelocity);
}


for (std::list<Bullet*>::iterator iter = _bullets.begin(); iter != _bullets.end(); ++iter)
{
	if ((*iter)->IsOutLimit())
	{
		delete (*iter);
		*iter = 0;
	}
}
//std::for_each(_bullets.begin(), _bullets.end(), DeleteBulletPointers);
_bullets.erase(std::remove(_bullets.begin(), _bullets.end(), static_cast<Bullet*>(0)), _bullets.end());
*/