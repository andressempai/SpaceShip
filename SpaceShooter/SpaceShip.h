#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();
	sf::Sprite DrawShip();
	sf::Sprite DrawFlame();
	void FlameAnimation();
private:
	sf::Sprite Ship;
	sf::Texture ShipTexture;
	sf::Sprite Flame;
	sf::Texture FlameTexture;
};