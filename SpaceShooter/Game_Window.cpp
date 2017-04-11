#include "Game_Window.h"

Game_Window::Game_Window()
{
	Setup("window", sf::Vector2u(640, 480));
}

Game_Window::Game_Window(const std::string& _spwindowtitle, const sf::Vector2u& _spwindowsize)
{
	Setup(_spwindowtitle, _spwindowsize);
}

Game_Window::~Game_Window()
{
	Destroy();
}

void Game_Window::Setup(const std::string& _spwindowtitle, const sf::Vector2u& _spwindowsize)
{
	sp_windowTitle = _spwindowtitle;
	sp_windowSize = _spwindowsize;
	sp_IsFullScreen = false;
	sp_IsDone = false;
	Create();
}

void Game_Window::Create()
{
	sf::Uint32 sp_windowStyle = (IsFullScreen() ? sf::Style::Fullscreen : sf::Style::Default);
	sp_window.create(
		sf::VideoMode(GetWindowSize().x, GetWindowSize().y),
		sp_windowTitle,
		sp_windowStyle);
}

void Game_Window::Destroy()
{
	sp_window.close();
}

void Game_Window::Update()
{
	sf::Event sp_event;
	while (sp_window.pollEvent(sp_event))
	{
		if (sp_event.type == sf::Event::Closed)
		{
			sp_IsDone = true;
		}
		else if (sp_event.type == sf::Event::KeyPressed
			&&
			sp_event.key.code == sf::Keyboard::F5)
		{
			ToggleFullScreen();
		}

		if (sp_event.type == sf::Event::MouseMoved)
		{
			sp_mouseMove = sf::Vector2f(
				sp_event.mouseMove.x,
				sp_event.mouseMove.y);
		}
	}
}

void Game_Window::BeforeDraw()
{
	sp_window.clear();
}

void Game_Window::Draw(sf::Drawable& _spobject)
{
	sp_window.draw(_spobject);
}

void Game_Window::DisplayDraw()
{
	sp_window.display();
}

void Game_Window::ToggleFullScreen()
{
	sp_IsFullScreen = !sp_IsFullScreen;
	Destroy();
	Create();
}

void Game_Window::FPS(const unsigned int _fps)
{
	sp_window.setFramerateLimit(_fps);
}

/* Getters */
sf::Vector2u Game_Window::GetWindowSize()
{
	return sp_windowSize;
}

sf::Vector2f Game_Window::GetMouseMove()
{
	return sp_mouseMove;
}

bool Game_Window::IsFullScreen()
{
	return sp_IsFullScreen;
}

bool Game_Window::IsDone()
{
	return sp_IsDone;
}