#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
	/* Ship Texture */
	if (!ShipTexture.loadFromFile("Data/SpaceShip.png"))
	{
		std::cout << "File not found" << std::endl;
	}
	Ship.setTexture(ShipTexture);

	/* Turbine Flame Texture */
	if (!FlameTexture.loadFromFile("Data/Flame_Animation.png"))
	{
		std::cout << "File not found" << std::endl;
	}
	Flame.setTexture(FlameTexture);
	Flame.setTextureRect(sf::IntRect(
		0,
		0,
		Flame.getTextureRect().height / 8,
		Flame.getTextureRect().width / 4));
}

SpaceShip::~SpaceShip()
{
}

sf::Sprite SpaceShip::DrawShip()
{
	return Ship;
}

sf::Sprite SpaceShip::DrawFlame()
{
	return Flame;
}

void SpaceShip::FlameAnimation()
{

}