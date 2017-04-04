#include <SFML\Graphics.hpp>
#include "SpaceShip.h"

int main()
{
	/* SFML Objects */
	sf::RenderWindow Game_Window(sf::VideoMode(720, 480), "SpaceShooter");
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

		/* Managing Events */
		while (Game_Window.pollEvent(Game_Event))
		{
			if (Game_Event.type == sf::Event::Closed)
			{
				Game_Window.close();
			}
		}

		/* Render */
		Game_Window.clear();
		Game_Window.draw(_spaceShip->DrawFlame());
		Game_Window.draw(_spaceShip->DrawShip());
		Game_Window.display();
	}

	return 0;
}