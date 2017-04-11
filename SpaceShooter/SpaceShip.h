#pragma once
#include <SFML\Graphics.hpp>
#include <map>

class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();
	
	/* Setters */
	void FlameAnimation(int);
	void Move(float, float, float);
	void GunPosition();

	/* Getters */
	sf::Sprite GetShip() const;
	sf::Sprite GetFlame() const;
	sf::Vector2f GetShipGunPosition();

private:
	/* Private Attributes */
	sf::Sprite sp_ship;
	sf::Texture sp_shipTexture;
	sf::Sprite sp_flame;
	sf::Texture sp_flameTexture;
	sf::Vector2f sp_gunPosition;
	std::map<int, sf::Vector2i> sp_flameFrameCoord;

	/* Private Methods */
	/* Setters */
	void Setup();
	void FlameFrameCoord();
};