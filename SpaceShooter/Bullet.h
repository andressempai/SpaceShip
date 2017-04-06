#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Bullet
{
public:
	Bullet(float, float);
	~Bullet();
	sf::Sprite DrawBullet();
	void SetVelocity(float);
	bool IsOutLimit();
private:
	/* Private Attributes */
	sf::Sprite BulletSprite;
	sf::Texture BulletTexture;

	/* Private Methods */
};