#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Bullet
{
public:
	Bullet();
	~Bullet();
	sf::Sprite DrawBullet();
	void SetToShipPosition(float, float);
	void SetVelocity(float);
private:
	/* Private Attributes */
	sf::Sprite BulletSprite;
	sf::Texture BulletTexture;

	/* Private Methods */
};