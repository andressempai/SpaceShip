#pragma once
#include <SFML\Graphics.hpp>
#include <map>

class Asteroid
{
public:
	Asteroid(int, float, float);
	~Asteroid();

	/* Setters */
	void Move(float);
	void SetFrame(int);
	void SetPosition(float);

	/* Getters */
	sf::Sprite GetAsteroid() const;
	bool IsInLimit();

private:
	/* Attributes */
	sf::Sprite sp_asteroid;
	sf::Texture sp_asteroidTexture;
	sf::Vector2f sp_increment;
	std::map<int, sf::Vector2i> sp_asteroidFrameCoord;

	/* Private Methods */
	void Setup();
	void AsteroidFrameCoord();
	void Crop(int);
	sf::Vector2f GetIncrement() const;
};