#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <map>

class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();
	sf::Sprite DrawShip();
	sf::Sprite DrawFlame();
	void FlameAnimation(int);
private:
	sf::Sprite Ship;
	sf::Texture ShipTexture;
	sf::Sprite Flame;
	sf::Texture FlameTexture;
	std::map<int, sf::Vector2i> FlameFrameCoord;
	void DefineFlameFrameAnimation();
};