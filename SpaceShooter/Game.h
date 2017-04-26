#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include "Game_Window.h"
#include "SpaceShip.h"
#include "AlienShip.h"
#include "Bullet.h"

class Game
{
public:
	Game();
	~Game();

	/* Setters */
	void HandleInput();
	void Update();
	void Render();
	void RestartClock();

	/* Getters */
	Game_Window* GetWindow();
	sf::Time GetElapsed();

private:
	/* Attributes */
	Game_Window sp_window;
	SpaceShip* sp_ship;
	AlienShip* sp_alienShip;
	std::list<Bullet*> sp_bullets;
	sf::Clock sp_clock;
	sf::Time sp_timeElapsed;
	int sp_flameIter;
	bool sp_shipShoot;

	/* Private Setters Methods */
	void Setup();
	void FPS();
};