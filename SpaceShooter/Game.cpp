#include "Game.h"

Game::Game() : sp_window("SpaceShooter", sf::Vector2u(1280, 720))
{
}

Game::~Game()
{
}

void Game::HandleInput()
{
}

void Game::Update()
{
	sp_window.Update();
}

void Game::Render()
{
	sp_window.BeforeDraw();
	//sp_window.Draw();
	sp_window.DisplayDraw();
}

Game_Window* Game::GetWindow()
{
	return &sp_window;
}