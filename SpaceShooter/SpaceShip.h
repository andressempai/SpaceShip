#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <map>

class SpaceShip
{
public:
	SpaceShip(float, float);
	~SpaceShip();
	sf::Sprite DrawShip();
	sf::Sprite DrawFlame();
	sf::CircleShape DrawShipPivot();
	void FlameAnimation(int);
	void MouseMove_Animation(float, float);
	float ShipGunGetPosX();
	float ShipGunGetPosY();
private:
	/* Private Attributes */
	sf::Sprite Ship;
	sf::Texture ShipTexture;
	sf::Sprite Flame;
	sf::Texture FlameTexture;
	std::map<int, sf::Vector2i> FlameFrameCoord;
	sf::CircleShape ShipPivot;

	/* Private Methods */
	void DefineFlameFrameAnimation();
};