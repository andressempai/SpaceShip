#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
	if (!ShipTexture.loadFromFile("Data/SpaceShip.png"))
	{
		Message = "File not found";
	}
	Ship.setTexture(ShipTexture);
}

SpaceShip::~SpaceShip()
{
}

sf::Sprite SpaceShip::DrawShip()
{
	return Ship;
}
