#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	virtual ~Game();
	bool Init();
	void Run();
private:
	sf::RenderWindow mWindow;
};