#include "Bullet.h"

Bullet::Bullet(sf::Vector2f& _bulletinitialpos)
{
	Setup();
	sp_bulletInitialPosition = _bulletinitialpos;
	sp_bullet.setPosition(sp_bulletInitialPosition);
}

void Bullet::Setup()
{
	/* Bullet Sprite Initial State */
	sp_bulletTexture.loadFromFile("Data/Bullet.png");
	sp_bullet.setTexture(sp_bulletTexture);
	sp_bullet.setOrigin(33.0f, 33.0f);
	sp_bullet.setScale(0.25f, 0.25f);
	sp_increment = sf::Vector2f(0.0f, 500.0f);
}

Bullet::~Bullet()
{
}

/* Setters */
void Bullet::Move(float _felapsed)
{
	if (sp_bullet.getPosition().y > 0.0f)
	{
		sp_bullet.setPosition(
			sp_bullet.getPosition().x - (GetIncrement().x),
			sp_bullet.getPosition().y - (GetIncrement().y * _felapsed)
		);
	}
}

/* Getters */
sf::Sprite Bullet::GetBullet()
{
	return sp_bullet;
}

sf::Vector2f Bullet::GetIncrement()
{
	return sp_increment;
}

bool Bullet::IsOutLimit()
{
	if (sp_bullet.getPosition().y < 1.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}