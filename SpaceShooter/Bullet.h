#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Bullet
{
public:
	Bullet(sf::Vector2f&);
	~Bullet();
	
	/* Setters */
	void Move(float);

	/* Getters */
	sf::Sprite GetBullet();
	sf::Vector2f GetIncrement();
	bool IsOutLimit();

private:
	/* Private Attributes */
	sf::Sprite sp_bullet;
	sf::Texture sp_bulletTexture;
	sf::Vector2f sp_bulletInitialPosition;
	sf::Vector2f sp_increment;

	/* Private Methods */
	void Setup();
};