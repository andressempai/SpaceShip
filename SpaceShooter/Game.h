#pragma once
#include "Game_Window.h"

class Game
{
public:
	Game();
	~Game();

	/* Setters */
	void HandleInput();
	void Update();
	void Render();

	/* Getters */
	Game_Window* GetWindow();

private:
	/* Attributes */
	Game_Window sp_window;
};