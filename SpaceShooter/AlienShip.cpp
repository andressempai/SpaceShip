#include "AlienShip.h"

AlienShip::AlienShip()
{
	/* Ship Texture */
	if (!ShipTexture.loadFromFile("Data/Alien_Ship05.png"))
	{
		std::cout << "File not found" << std::endl;
	}
	Ship.setTexture(ShipTexture);
}

AlienShip::~AlienShip()
{
}

sf::Sprite AlienShip::DrawAlienShip() const
{
	return Ship;
}