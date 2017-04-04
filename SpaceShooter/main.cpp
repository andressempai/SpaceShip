#include <SFML\Graphics.hpp>

int main()
{
	/** SFML Objects **/
	sf::RenderWindow Game_Window(sf::VideoMode(720, 480), "SpaceShooter");
	sf::Event Game_Event;

	/** Game Loop **/
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
		Game_Window.display();
	}


	return 0;
}