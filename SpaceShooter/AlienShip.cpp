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
	sp_alienShip.setScale(0.4f, 0.4f);
	sp_alienShip.setOrigin(
		sp_alienShipTexture.getSize().x / 2,
		sp_alienShipTexture.getSize().y / 2);
	sp_alienShip.setPosition(
		1280 / 2,
		(sp_alienShipTexture.getSize().y / 2) * 0.4f);
	sp_increment = sf::Vector2f(500.0f, 500.0f);
}

/* Setters */
void AlienShip::Update()
{
}

void AlienShip::Move(float _felapsed)
{
	sp_alienShip.setPosition(
		sp_alienShip.getPosition().x,
		sp_alienShip.getPosition().y + (GetIncrement().y * _felapsed));
}

/* Getters */
sf::Sprite AlienShip::GetAlienShip() const
{
	return sp_alienShip;
}

sf::Vector2f AlienShip::GetIncrement() const
{
	return sp_increment;
}

sf::Vector2f AlienShip::GetInitialPosition()
{
	return sp_alienShip.getPosition();
}