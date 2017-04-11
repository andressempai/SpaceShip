#pragma once
#include "Game_Window.h"
#include "SpaceShip.h"
#include "AlienShip.h"
#include <iostream>

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
	sf::Clock sp_clock;
	sf::Time sp_timeElapsed;
	int sp_flameIter;

	/* Private Setters Methods */
	void Setup();
	void FPS();
};