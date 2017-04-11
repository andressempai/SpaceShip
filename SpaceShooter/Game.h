#pragma once
#include "Game_Window.h"
#include "AlienShip.h"

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
	AlienShip* sp_alienShip;
	sf::Clock sp_clock;
	sf::Time sp_timeElapsed;

	/* Private Setters Methods */
	void Setup();
	void FPS();
};