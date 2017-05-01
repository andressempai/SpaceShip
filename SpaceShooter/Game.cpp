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
	sp_shipShoot = false;
	FPS();
}

void Game::HandleInput()
{
	if (sp_window.GetLeftClickInput())
	{
		sp_shipShoot = true;
	}
}

void Game::Update()
{
	float fElapsed = GetElapsed().asSeconds();

	sp_window.Update();

	/* Ship Animation */
	sp_ship->Move(
		0.0f,
		sp_window.GetMouseMove().x,
		sp_window.GetMouseMove().y);

	/* Alien Ship Animation*/
	sp_alienShip->Move(fElapsed);

	/* Flame Animation */
	if (sp_flameIter < 32)
	{
		++sp_flameIter;
	}
	else
	{
		sp_flameIter = 1;
	}

	sp_ship->FlameAnimation(sp_flameIter);
	/* End Flame Animation */

	/* Bullets Creation */
	if (sp_shipShoot)
	{
		sp_bullets.push_back(new Bullet(sf::Vector2f(sp_ship->GetShipGunPosition())));
		sp_shipShoot = false;
		sp_window.SetLeftClickInput();
	}

	/* Bullets Animation */
	for (std::list<Bullet*>::iterator iter = sp_bullets.begin(); iter != sp_bullets.end(); ++iter)
	{
		(*iter)->Move(fElapsed);
	}
	/* End Bullets Animation */

	/* Delete Unused Bullets */
	for (std::list<Bullet*>::iterator iter = sp_bullets.begin(); iter != sp_bullets.end(); ++iter)
	{
		if ((*iter)->IsOutLimit())
		{
			delete (*iter);
			*iter = 0;
		}
	}

	//std::for_each(_bullets.begin(), _bullets.end(), DeleteBulletPointers);
	sp_bullets.erase(
		std::remove(sp_bullets.begin(), sp_bullets.end(), static_cast<Bullet*>(0)),
		sp_bullets.end());
	/* End Delete Unused Bullets */
}

void Game::Render()
{
	sp_window.BeforeDraw();

	/* Space Ship Draw */
	sp_window.Draw(sp_ship->GetFlame());
	sp_window.Draw(sp_ship->GetShip());

	/* Bullets Draw */
	if (!sp_bullets.empty())
	{
		for (std::list<Bullet*>::iterator iter = sp_bullets.begin(); iter != sp_bullets.end(); ++iter)
		{
			sp_window.Draw((*iter)->GetBullet());
		}
	}

	/* Alien Ship Draw */
	sp_window.Draw(sp_alienShip->GetAlienShip());
	sp_window.Draw(sp_alienShip->GetLifeBar());

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