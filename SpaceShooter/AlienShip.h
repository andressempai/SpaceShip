#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class AlienShip
{
public:
	AlienShip();
	~AlienShip();
	sf::Sprite DrawAlienShip() const;

private:
	/* Private Attributes */
	sf::Sprite Ship;
	sf::Texture ShipTexture;

	/* Private Methods */
	
};