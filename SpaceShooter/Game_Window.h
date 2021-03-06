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
	void SetLeftClickInput();

	/* Getters */
	sf::Vector2u GetWindowSize();
	sf::Vector2f GetMouseMove();
	bool IsFullScreen();
	bool IsDone();
	bool GetLeftClickInput();

private:
	/* Attributes */
	sf::RenderWindow sp_window;
	sf::Vector2u sp_windowSize;
	std::string sp_windowTitle;
	sf::Vector2f sp_mouseMove;
	bool sp_IsFullScreen;
	bool sp_IsDone;
	bool sp_leftClick;

	/* Methods */
	void Setup(const std::string&, const sf::Vector2u&);
	void Create();
	void Destroy();
};