#include <SFML\Graphics.hpp>
#include "SpaceShip.h"

int main()
{
	/* SFML Objects */
	sf::RenderWindow Game_Window(sf::VideoMode(1280, 720), "SpaceShooter");
	sf::Event Game_Event;

	/* Custom Objects*/
	SpaceShip* _spaceShip = new SpaceShip();

	/* Variables */
	int FlameIter = 1;

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

		/* Render */
		Game_Window.clear();
		Game_Window.draw(_spaceShip->DrawFlame());
		Game_Window.draw(_spaceShip->DrawShip());
		Game_Window.draw(_spaceShip->DrawShipPivot());
		Game_Window.display();
	}

	/* Clear all Pointers */
	delete _spaceShip;

	return 0;
}