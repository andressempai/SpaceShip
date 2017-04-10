#include "Game.h"

Game::Game() : sp_window("SpaceShooter", sf::Vector2u(1280, 720))
{
	FPS();
}

Game::~Game()
{
}

void Game::HandleInput()
{
	sf::Event sp_inputEvent;
}

void Game::Update()
{
	float fElapsed = GetElapsed().asSeconds();
	sp_window.Update();
	sp_alienShip.Move(fElapsed);
}

void Game::Render()
{
	sp_window.BeforeDraw();
	sp_window.Draw(sp_alienShip.GetAlienShip());
	sp_window.DisplayDraw();
}

void Game::RestartClock()
{
	sp_timeElapsed = sp_clock.restart();
}

void Game::FPS()
{
	sp_window.FPS(60);
}

Game_Window* Game::GetWindow()
{
	return &sp_window;
}

sf::Time Game::GetElapsed()
{
	return sp_timeElapsed;
}