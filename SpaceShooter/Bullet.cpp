#include "Bullet.h"

Bullet::Bullet(float _x, float _y)
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
	BulletSprite.setPosition(_x, _y);
}

Bullet::~Bullet()
{
}

sf::Sprite Bullet::DrawBullet()
{
	return BulletSprite;
}

void Bullet::SetVelocity(float _vel)
{
	if (BulletSprite.getPosition().y > 0.0f)
	{
		BulletSprite.move(0.0f, -_vel);
	}
}

bool Bullet::IsOutLimit() const
{
	if (BulletSprite.getPosition().y < 1.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}