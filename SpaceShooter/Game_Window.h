#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class Game_Window
{
public:
	Game_Window();
	Game_Window(const std::string&, const sf::Vector2u&);
	~Game_Window();

	/* Update */
	void Update();

	/* Render */
	void BeforeDraw();
	void Draw(sf::Drawable&);
	void DisplayDraw();

	/* Setters */
	void ToggleFullScreen();
	void FPS(const unsigned int);

	/* Getters */
	sf::Vector2u GetWindowSize();
	bool IsFullScreen();
	bool IsDone();

private:
	/* Attributes */
	sf::RenderWindow sp_window;
	sf::Vector2u sp_windowSize;
	std::string sp_windowTitle;
	bool sp_IsFullScreen;
	bool sp_IsDone;

	/* Methods */
	void Setup(const std::string&, const sf::Vector2u&);
	void Create();
	void Destroy();
};