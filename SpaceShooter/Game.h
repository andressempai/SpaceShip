#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <list>
#include "Game_Window.h"
#include "SpaceShip.h"
#include "AlienShip.h"
#include "Bullet.h"
#include "Asteroid.h"

class Game
{
public:
	Game();
	~Game();

	/* Setters */
	void HandleInput();
	void Update(int);
	void Render();
	void RestartClock();

	/* Getters */
	Game_Window* GetWindow();
	sf::Time GetElapsed();

private:
	/* Attributes */
	Game_Window sp_window;
	SpaceShip* sp_ship;
	//AlienShip* sp_alienShip;
	std::list<Bullet*> sp_bullets;
	std::list<Asteroid*> sp_asteroid;
	sf::Clock sp_clock;
	sf::Time sp_timeElapsed;
	int sp_flameIter;
	bool sp_shipShoot;

	/* Private Setters Methods */
	void Setup();
	void FPS();
};