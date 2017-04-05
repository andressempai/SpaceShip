#include <SFML\Graphics.hpp>
#include "SpaceShip.h"
#include "Bullet.h"

int main()
{
	/* SFML Objects */
	sf::RenderWindow Game_Window(sf::VideoMode(1280, 720), "SpaceShooter");
	sf::Event Game_Event;

	/* Custom Objects*/
	SpaceShip* _spaceShip = new SpaceShip();
	Bullet* _bullet = new Bullet();

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
				_bullet->SetToShipPosition(
					_spaceShip->DrawShip().getPosition().x,
					_spaceShip->DrawShip().getPosition().y -
					_spaceShip->DrawShip().getTextureRect().height / 2 * 0.3);
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
		_bullet->SetVelocity(BulletVelocity);

		/* Render */
		Game_Window.clear();
		Game_Window.draw(_bullet->DrawBullet());
		Game_Window.draw(_spaceShip->DrawFlame());
		Game_Window.draw(_spaceShip->DrawShip());
		Game_Window.draw(_spaceShip->DrawShipPivot());
		Game_Window.display();
	}

	/* Clear all Pointers */
	delete _spaceShip;

	return 0;
}