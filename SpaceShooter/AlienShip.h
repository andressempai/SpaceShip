#pragma once
#include <SFML\Graphics.hpp>

class AlienShip
{
public:
	AlienShip();
	~AlienShip();

	/* Setters */
	void Update();

	/* Getters */
	sf::Sprite GetAlienShip() const;

private:
	/* Private Attributes */
	sf::Sprite sp_alienShip;
	sf::Texture sp_alienShipTexture;
	sf::Vector2f sp_increment;

	/* Private Methods */
	void Setup();
};