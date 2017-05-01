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
	sp_increment = sf::Vector2f(0.0f, 0.0f);

	/* Life Bar */
	sp_lifeBar.setSize(
		sf::Vector2f(sp_alienShip.getGlobalBounds().width, 10.0f)
	);
	sp_lifeBar.setFillColor(sf::Color::Red);
	sp_lifeBar.setPosition(
		sp_alienShip.getPosition().x - (sp_alienShip.getGlobalBounds().width / 2),
		sp_alienShip.getPosition().y - (sp_alienShip.getGlobalBounds().height / 2)
	);

	sp_lifePercentage = 1.0f;
}

/* Setters */
void AlienShip::Move(float _felapsed)
{
	sp_alienShip.setPosition(
		sp_alienShip.getPosition().x + (GetIncrement().x * _felapsed),
		sp_alienShip.getPosition().y + (GetIncrement().y * _felapsed));
}

/* Getters */
sf::Sprite AlienShip::GetAlienShip() const
{
	return sp_alienShip;
}

sf::RectangleShape AlienShip::GetLifeBar() const
{
	return sp_lifeBar;
}

sf::Vector2f AlienShip::GetIncrement() const
{
	return sp_increment;
}

sf::Vector2f AlienShip::GetInitialPosition()
{
	return sp_alienShip.getPosition();
}