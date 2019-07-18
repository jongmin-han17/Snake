#pragma once
#include "Circle.h"

class Game
{
public:
	Game();
	virtual ~Game();
	bool Init();
	void Run();
private:
	const int GAME_WIDTH = 1280;
	const int GAME_HEIGHT = 720;
	sf::RenderWindow mWindow;
};