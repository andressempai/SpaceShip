#include "Game.h"

Game::Game() : sp_window("SpaceShooter", sf::Vector2u(1280, 720))
{
	Setup();
}

Game::~Game()
{
}

void Game::Setup()
{
	sp_ship = new SpaceShip();
	sp_alienShip = new AlienShip();
	sp_flameIter = 0;
	FPS();
}

void Game::HandleInput()
{
	sf::Event sp_inputEvent;

	/* Mouse Move Event */
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Space Key Pressed" << std::endl;
	}*/
}

void Game::Update()
{
	float fElapsed = GetElapsed().asSeconds();

	sp_window.Update();
	sp_ship->Move(
		0.0f,
		sp_window.GetMouseMove().x,
		sp_window.GetMouseMove().y);
	sp_alienShip->Move(fElapsed);

	if (sp_flameIter < 32)
	{
		++sp_flameIter;
	}
	else
	{
		sp_flameIter = 1;
	}

	sp_ship->FlameAnimation(sp_flameIter);
}

void Game::Render()
{
	sp_window.BeforeDraw();

	/* Space Ship Draw */
	sp_window.Draw(sp_ship->GetFlame());
	sp_window.Draw(sp_ship->GetShip());

	/* Alien Ship Draw */
	sp_window.Draw(sp_alienShip->GetAlienShip());

	/* Display All Objects */
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