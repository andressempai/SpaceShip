#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
	Setup();
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::Setup()
{
	/* Ship Sprite Initial State */
	sp_shipTexture.loadFromFile("Data/SpaceShip.png");
	sp_ship.setTexture(sp_shipTexture);
	sp_ship.setScale(0.3f, 0.3f);
	sp_ship.setOrigin(
		sp_shipTexture.getSize().x / 2,
		sp_shipTexture.getSize().y / 2);
	sp_ship.setPosition(
		1280 / 2,
		1280 / 2);

	/* Flame Sprite Initial State */
	sp_flameTexture.loadFromFile("Data/Flame_Animation.png");
	sp_flame.setTexture(sp_flameTexture);
	FlameFrameCoord();
	sp_flame.setOrigin(32, 64);
	sp_flame.setRotation(180.0f);
	sp_flame.setPosition(
		sp_ship.getPosition().x,
		sp_ship.getPosition().y + 53);
	sp_flame.setScale(0.3f, 0.3f);
}

/* Setters */
void SpaceShip::FlameFrameCoord()
{
	sp_flameFrameCoord[1] = sf::Vector2i(0, 0);
	sp_flameFrameCoord[2] = sf::Vector2i(64, 0);
	sp_flameFrameCoord[3] = sf::Vector2i(128, 0);
	sp_flameFrameCoord[4] = sf::Vector2i(192, 0);
	sp_flameFrameCoord[5] = sf::Vector2i(256, 0);
	sp_flameFrameCoord[6] = sf::Vector2i(320, 0);
	sp_flameFrameCoord[7] = sf::Vector2i(384, 0);
	sp_flameFrameCoord[8] = sf::Vector2i(448, 0);
	sp_flameFrameCoord[9] = sf::Vector2i(0, 128);
	sp_flameFrameCoord[10] = sf::Vector2i(64, 128);
	sp_flameFrameCoord[11] = sf::Vector2i(128, 128);
	sp_flameFrameCoord[12] = sf::Vector2i(192, 128);
	sp_flameFrameCoord[13] = sf::Vector2i(256, 128);
	sp_flameFrameCoord[14] = sf::Vector2i(320, 128);
	sp_flameFrameCoord[15] = sf::Vector2i(384, 128);
	sp_flameFrameCoord[16] = sf::Vector2i(448, 128);
	sp_flameFrameCoord[17] = sf::Vector2i(0, 256);
	sp_flameFrameCoord[18] = sf::Vector2i(64, 256);
	sp_flameFrameCoord[19] = sf::Vector2i(128, 256);
	sp_flameFrameCoord[20] = sf::Vector2i(192, 256);
	sp_flameFrameCoord[21] = sf::Vector2i(256, 256);
	sp_flameFrameCoord[22] = sf::Vector2i(320, 256);
	sp_flameFrameCoord[23] = sf::Vector2i(384, 256);
	sp_flameFrameCoord[24] = sf::Vector2i(448, 256);
	sp_flameFrameCoord[25] = sf::Vector2i(0, 384);
	sp_flameFrameCoord[26] = sf::Vector2i(64, 384);
	sp_flameFrameCoord[27] = sf::Vector2i(128, 384);
	sp_flameFrameCoord[28] = sf::Vector2i(192, 384);
	sp_flameFrameCoord[29] = sf::Vector2i(256, 384);
	sp_flameFrameCoord[30] = sf::Vector2i(320, 384);
	sp_flameFrameCoord[31] = sf::Vector2i(384, 384);
	sp_flameFrameCoord[32] = sf::Vector2i(448, 384);
}

void SpaceShip::FlameAnimation(int _iter)
{
	/* Set Flame Animation */
	sp_flame.setTextureRect(
		sf::IntRect(
			sp_flameFrameCoord[_iter].x,
			sp_flameFrameCoord[_iter].y, 64, 128));
}

void SpaceShip::Move(float _felapsed, float _x, float _y)
{
	sp_ship.setPosition(_x, _y);
	sp_flame.setPosition(
		sp_ship.getPosition().x,
		sp_ship.getPosition().y + 53);
}

void SpaceShip::GunPosition()
{
	sp_gunPosition = sf::Vector2f(
		sp_ship.getPosition().x,
		sp_ship.getPosition().y - ((sp_shipTexture.getSize().y / 2) * 0.3f));
}

/* Getters */
sf::Sprite SpaceShip::GetShip() const
{
	return sp_ship;
}

sf::Sprite SpaceShip::GetFlame() const
{
	return sp_flame;
}

sf::Vector2f SpaceShip::GetShipGunPosition()
{
	return sp_gunPosition;
}