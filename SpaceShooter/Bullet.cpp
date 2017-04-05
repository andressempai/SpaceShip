#include "Bullet.h"

Bullet::Bullet()
{
	/* Bullet Texture */
	if (!BulletTexture.loadFromFile("Data/Bullet.png"))
	{
		std::cout << "File not found" << std::endl;
	}
	BulletSprite.setTexture(BulletTexture);

	/* Sprites And Objects Initial States */
		/* Bullet Sprites */
	BulletSprite.setOrigin(33.0f, 33.0f);
	BulletSprite.setScale(0.25f, 0.25f);
}

Bullet::~Bullet()
{
}

sf::Sprite Bullet::DrawBullet()
{
	return BulletSprite;
}

void Bullet::SetToShipPosition(float _x, float _y)
{
	BulletSprite.setPosition(_x, _y);
}

void Bullet::SetVelocity(float _vel)
{
	BulletSprite.move(0.0f, -_vel);
}