#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();
	sf::Sprite DrawShip();
private:
	sf::Sprite Ship;
	sf::Texture ShipTexture;
	std::string Message;
};