#include "AlienShip.h"

AlienShip::AlienShip()
{
	Setup();
}

AlienShip::~AlienShip()
{
}

void AlienShip::Setup()
{
	sp_alienShipTexture.loadFromFile("Data/Alien_Ship05.png");
	sp_alienShip.setTexture(sp_alienShipTexture);
	sp_alienShip.setOrigin(
		sp_alienShipTexture.getSize().x / 2,
		sp_alienShipTexture.getSize().y / 2);
	sp_increment = sf::Vector2f(5.0f, 5.0f);
}

/* Setters */
void AlienShip::Update()
{

}

/* Getters */
sf::Sprite AlienShip::GetAlienShip() const
{
	return sp_alienShip;
}