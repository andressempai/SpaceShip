#include "SpaceShip.h"

SpaceShip::SpaceShip(float _x, float _y)
{
	/* Ship Texture */
	if (!ShipTexture.loadFromFile("Data/SpaceShip.png"))
	{
		std::cout << "File not found" << std::endl;
	}
	Ship.setTexture(ShipTexture);

	/* Turbine Flame Texture */
	if (!FlameTexture.loadFromFile("Data/Flame_Animation.png"))
	{
		std::cout << "File not found" << std::endl;
	}
	Flame.setTexture(FlameTexture);

	/* Flame Frames Animation */
	DefineFlameFrameAnimation();

	/* Sprites And Objects Initial States */
		/* ShipPivot */
	ShipPivot.setRadius(5.0f);
	ShipPivot.setFillColor(sf::Color::Red);
	ShipPivot.setOrigin(ShipPivot.getRadius() / 2, ShipPivot.getRadius() / 2);
	ShipPivot.setPosition(_x, _y);

		/* Ship Sprite*/
	Ship.setOrigin(Ship.getTextureRect().height / 2, Ship.getTextureRect().width / 2);
	Ship.setScale(0.3f, 0.3f);
	Ship.setPosition(ShipPivot.getPosition());

		/* Flame Sprite */
	Flame.setOrigin(32, 64);
	Flame.setRotation(180.0f);
	Flame.setPosition(Ship.getPosition().x, Ship.getPosition().y + 53);
	Flame.setScale(0.3f, 0.3f);
}

SpaceShip::~SpaceShip()
{
}

sf::Sprite SpaceShip::DrawShip()
{
	return Ship;
}

sf::Sprite SpaceShip::DrawFlame()
{
	return Flame;
}

sf::CircleShape SpaceShip::DrawShipPivot()
{
	return ShipPivot;
}

void SpaceShip::DefineFlameFrameAnimation()
{
	FlameFrameCoord[1] = sf::Vector2i(0, 0);
	FlameFrameCoord[2] = sf::Vector2i(64, 0);
	FlameFrameCoord[3] = sf::Vector2i(128, 0);
	FlameFrameCoord[4] = sf::Vector2i(192, 0);
	FlameFrameCoord[5] = sf::Vector2i(256, 0);
	FlameFrameCoord[6] = sf::Vector2i(320, 0);
	FlameFrameCoord[7] = sf::Vector2i(384, 0);
	FlameFrameCoord[8] = sf::Vector2i(448, 0);
	FlameFrameCoord[9] = sf::Vector2i(0, 128);
	FlameFrameCoord[10] = sf::Vector2i(64, 128);
	FlameFrameCoord[11] = sf::Vector2i(128, 128);
	FlameFrameCoord[12] = sf::Vector2i(192, 128);
	FlameFrameCoord[13] = sf::Vector2i(256, 128);
	FlameFrameCoord[14] = sf::Vector2i(320, 128);
	FlameFrameCoord[15] = sf::Vector2i(384, 128);
	FlameFrameCoord[16] = sf::Vector2i(448, 128);
	FlameFrameCoord[17] = sf::Vector2i(0, 256);
	FlameFrameCoord[18] = sf::Vector2i(64, 256);
	FlameFrameCoord[19] = sf::Vector2i(128, 256);
	FlameFrameCoord[20] = sf::Vector2i(192, 256);
	FlameFrameCoord[21] = sf::Vector2i(256, 256);
	FlameFrameCoord[22] = sf::Vector2i(320, 256);
	FlameFrameCoord[23] = sf::Vector2i(384, 256);
	FlameFrameCoord[24] = sf::Vector2i(448, 256);
	FlameFrameCoord[25] = sf::Vector2i(0, 384);
	FlameFrameCoord[26] = sf::Vector2i(64, 384);
	FlameFrameCoord[27] = sf::Vector2i(128, 384);
	FlameFrameCoord[28] = sf::Vector2i(192, 384);
	FlameFrameCoord[29] = sf::Vector2i(256, 384);
	FlameFrameCoord[30] = sf::Vector2i(320, 384);
	FlameFrameCoord[31] = sf::Vector2i(384, 384);
	FlameFrameCoord[32] = sf::Vector2i(448, 384);
}

void SpaceShip::FlameAnimation(int _iter)
{
	/* Set Flame Animation */
	Flame.setTextureRect(sf::IntRect(FlameFrameCoord[_iter].x, FlameFrameCoord[_iter].y, 64, 128));
}

void SpaceShip::MouseMove_Animation(float _x, float _y)
{
	ShipPivot.setPosition(_x, _y);
	Ship.setPosition(ShipPivot.getPosition());
	Flame.setPosition(Ship.getPosition().x, Ship.getPosition().y + 53);
}

float SpaceShip::ShipGunGetPosX()
{
	return Ship.getPosition().x;
}

float SpaceShip::ShipGunGetPosY()
{
	return Ship.getPosition().y - ((Ship.getTextureRect().height / 2) * 0.3);
}