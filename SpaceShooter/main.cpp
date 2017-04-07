#include <SFML\Graphics.hpp>
#include <algorithm>
#include <list>
#include "SpaceShip.h"
#include "Bullet.h"
#include "AlienShip.h"

int main()
{
	/* SFML Objects */
	sf::RenderWindow Game_Window(sf::VideoMode(1280, 720), "SpaceShooter");
	sf::Event Game_Event;

	/* Custom Objects*/
	SpaceShip* _spaceShip = new SpaceShip(float(1280 / 2), float(1280 / 2));
	std::list<Bullet*> _bullets;
	AlienShip* _alienShip = new AlienShip();

	/* Variables */
	int FlameIter = 1;
	float BulletVelocity = 10.0f;

	/* Game Seting */
	Game_Window.setFramerateLimit(60);

	/* Game Loop */
	while (Game_Window.isOpen())
	{
		/* Managing Events */
		while (Game_Window.pollEvent(Game_Event))
		{
			/* Window Closed Event */
			if (Game_Event.type == sf::Event::Closed)
			{
				Game_Window.close();
			}

			/* Mouse Move Event */
			if (Game_Event.type == sf::Event::MouseMoved)
			{
				_spaceShip->MouseMove_Animation(Game_Event.mouseMove.x, Game_Event.mouseMove.y);
			}

			/* Mouse Pressed Event */
			if (Game_Event.type == sf::Event::MouseButtonPressed
				&&
				Game_Event.mouseButton.button == sf::Mouse::Left)
			{
				_bullets.push_back(new Bullet(_spaceShip->ShipGunGetPosX(), _spaceShip->ShipGunGetPosY()));
			}
		}

		/* Game Logic */
		/* Loop Animation*/
		if (FlameIter < 32)
		{
			++FlameIter;
		}
		else
		{
			FlameIter = 1;
		}

		_spaceShip->FlameAnimation(FlameIter);

		/* Bullet Animation */
		for (std::list<Bullet*>::iterator Aiter = _bullets.begin(); Aiter != _bullets.end(); ++Aiter)
		{
			(*Aiter)->SetVelocity(BulletVelocity);
		}

		/* Delete Bullet Pointers */
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
		std::cout << "Number of Bullets are: " << _bullets.size() << std::endl;

		/* Render */
		Game_Window.clear();

			/* Bullets Draw */
		for (std::list<Bullet*>::iterator Diter = _bullets.begin(); Diter != _bullets.end(); ++Diter)
		{
			Game_Window.draw((*Diter)->DrawBullet());
		}

			/* Ship  Draw */
		Game_Window.draw(_spaceShip->DrawFlame());
		Game_Window.draw(_spaceShip->DrawShip());
		Game_Window.draw(_spaceShip->DrawShipPivot());

			/* Alien Ship Draw */
		Game_Window.draw(_alienShip->DrawAlienShip());

			/* Display All */
		Game_Window.display();
	}

	return 0;
}