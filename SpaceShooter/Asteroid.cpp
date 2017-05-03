#include "Asteroid.h"

Asteroid::Asteroid(int _frame, float _xCoord, float _yCoord)
{
	this->Setup();
	this->AsteroidFrameCoord();

	this->Crop(_frame);
	this->sp_asteroid.setPosition(sf::Vector2f(_xCoord, _yCoord));
}

Asteroid::~Asteroid()
{
}

void Asteroid::Setup()
{
	sp_asteroidTexture.loadFromFile("Data/Asteroids.png");
	sp_asteroid.setTexture(sp_asteroidTexture);
	sp_asteroid.setOrigin(64.0f, 64.0f);
	sp_asteroid.setScale(0.25f, 0.25f);
	sp_increment = sf::Vector2f(0.0f, 250.0f);
}

void Asteroid::AsteroidFrameCoord()
{
	sp_asteroidFrameCoord[1] = sf::Vector2i(0, 0);
	sp_asteroidFrameCoord[2] = sf::Vector2i(128, 0);
	sp_asteroidFrameCoord[3] = sf::Vector2i(256, 0);
	sp_asteroidFrameCoord[4] = sf::Vector2i(384, 0);
	sp_asteroidFrameCoord[5] = sf::Vector2i(512, 0);
	sp_asteroidFrameCoord[6] = sf::Vector2i(640, 0);
	sp_asteroidFrameCoord[7] = sf::Vector2i(768, 0);
	sp_asteroidFrameCoord[8] = sf::Vector2i(896, 0);
	sp_asteroidFrameCoord[9] = sf::Vector2i(0, 128);
	sp_asteroidFrameCoord[10] = sf::Vector2i(128, 128);
	sp_asteroidFrameCoord[11] = sf::Vector2i(256, 128);
	sp_asteroidFrameCoord[12] = sf::Vector2i(384, 128);
	sp_asteroidFrameCoord[13] = sf::Vector2i(512, 128);
	sp_asteroidFrameCoord[14] = sf::Vector2i(640, 128);
	sp_asteroidFrameCoord[15] = sf::Vector2i(768, 128);
	sp_asteroidFrameCoord[16] = sf::Vector2i(896, 128);
	sp_asteroidFrameCoord[17] = sf::Vector2i(0, 256);
	sp_asteroidFrameCoord[18] = sf::Vector2i(128, 256);
	sp_asteroidFrameCoord[19] = sf::Vector2i(256, 256);
	sp_asteroidFrameCoord[20] = sf::Vector2i(384, 256);
	sp_asteroidFrameCoord[21] = sf::Vector2i(512, 256);
	sp_asteroidFrameCoord[22] = sf::Vector2i(640, 256);
	sp_asteroidFrameCoord[23] = sf::Vector2i(768, 256);
	sp_asteroidFrameCoord[24] = sf::Vector2i(896, 256);
	sp_asteroidFrameCoord[25] = sf::Vector2i(0, 384);
	sp_asteroidFrameCoord[26] = sf::Vector2i(128, 384);
	sp_asteroidFrameCoord[27] = sf::Vector2i(256, 384);
	sp_asteroidFrameCoord[28] = sf::Vector2i(384, 384);
	sp_asteroidFrameCoord[29] = sf::Vector2i(512, 384);
	sp_asteroidFrameCoord[30] = sf::Vector2i(640, 384);
	sp_asteroidFrameCoord[31] = sf::Vector2i(768, 384);
	sp_asteroidFrameCoord[32] = sf::Vector2i(896, 384);
	sp_asteroidFrameCoord[33] = sf::Vector2i(0, 512);
	sp_asteroidFrameCoord[34] = sf::Vector2i(128, 512);
	sp_asteroidFrameCoord[35] = sf::Vector2i(256, 512);
	sp_asteroidFrameCoord[36] = sf::Vector2i(384, 512);
	sp_asteroidFrameCoord[37] = sf::Vector2i(512, 512);
	sp_asteroidFrameCoord[38] = sf::Vector2i(640, 512);
	sp_asteroidFrameCoord[39] = sf::Vector2i(768, 512);
	sp_asteroidFrameCoord[40] = sf::Vector2i(896, 512);
	sp_asteroidFrameCoord[41] = sf::Vector2i(0, 640);
	sp_asteroidFrameCoord[42] = sf::Vector2i(128, 640);
	sp_asteroidFrameCoord[43] = sf::Vector2i(256, 640);
	sp_asteroidFrameCoord[44] = sf::Vector2i(384, 640);
	sp_asteroidFrameCoord[45] = sf::Vector2i(512, 640);
	sp_asteroidFrameCoord[46] = sf::Vector2i(640, 640);
	sp_asteroidFrameCoord[47] = sf::Vector2i(768, 640);
	sp_asteroidFrameCoord[48] = sf::Vector2i(896, 640);
	sp_asteroidFrameCoord[49] = sf::Vector2i(0, 768);
	sp_asteroidFrameCoord[50] = sf::Vector2i(128, 768);
	sp_asteroidFrameCoord[51] = sf::Vector2i(256, 768);
	sp_asteroidFrameCoord[52] = sf::Vector2i(384, 768);
	sp_asteroidFrameCoord[53] = sf::Vector2i(512, 768);
	sp_asteroidFrameCoord[54] = sf::Vector2i(640, 768);
	sp_asteroidFrameCoord[55] = sf::Vector2i(768, 768);
	sp_asteroidFrameCoord[56] = sf::Vector2i(896, 768);
	sp_asteroidFrameCoord[57] = sf::Vector2i(0, 896);
	sp_asteroidFrameCoord[58] = sf::Vector2i(128, 896);
	sp_asteroidFrameCoord[59] = sf::Vector2i(256, 896);
	sp_asteroidFrameCoord[60] = sf::Vector2i(384, 896);
	sp_asteroidFrameCoord[61] = sf::Vector2i(512, 896);
	sp_asteroidFrameCoord[62] = sf::Vector2i(640, 896);
	sp_asteroidFrameCoord[63] = sf::Vector2i(768, 896);
	sp_asteroidFrameCoord[64] = sf::Vector2i(896, 896);
}

/* Setters */
void Asteroid::Crop(int _frame)
{
	sp_asteroid.setTextureRect(sf::IntRect(
		sp_asteroidFrameCoord[_frame].x,
		sp_asteroidFrameCoord[_frame].y,
		128, 128));
}

void Asteroid::Move(float _felapsed)
{
	if (IsInLimit())
	{
		sp_asteroid.setPosition(
			sp_asteroid.getPosition().x + GetIncrement().x,
			sp_asteroid.getPosition().y + (GetIncrement().y * _felapsed));
	}
}

void Asteroid::SetFrame(int _frame)
{
	Crop(_frame);
}

void Asteroid::SetPosition(float _xCoord)
{
	sp_asteroid.setPosition(sf::Vector2f(_xCoord, -10.0f));
}

/* Getters */
sf::Sprite Asteroid::GetAsteroid() const
{
	return sp_asteroid;
}

sf::Vector2f Asteroid::GetIncrement() const
{
	return sp_increment;
}

bool Asteroid::IsInLimit()
{
	if (sp_asteroid.getPosition().y < 750.0f)
	{
		return true;
	}
	else
	{
		return false;
	}
}