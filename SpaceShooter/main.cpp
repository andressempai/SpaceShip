#include <SFML\Graphics.hpp>
#include <iostream>
#include "SpaceShip.h"

int main()
{
	/* SFML Objects */
	sf::RenderWindow Game_Window(sf::VideoMode(720, 480), "SpaceShooter");
	sf::Event Game_Event;

	/* Custom Objects*/
	SpaceShip* _spaceShip = new SpaceShip();

	/* Game Loop */
	while (Game_Window.isOpen())
	{

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
		Game_Window.draw(_spaceShip->DrawShip());
		Game_Window.display();
	}

	return 0;
}