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
	void FPS();

	/* Getters */
	Game_Window* GetWindow();

private:
	/* Attributes */
	Game_Window sp_window;
	AlienShip sp_alienShip;
};