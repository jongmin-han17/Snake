#pragma once
#include "Circle.h"
#include <vector>

class Game
{
public:
	Game();
	virtual ~Game();
	bool Init();
	void Run();
	void MoveSnake(float x, float y);
private:
	const int GAME_WIDTH = 1280;
	const int GAME_HEIGHT = 720;
	sf::RenderWindow mWindow;
	std::vector<Circle*> mSnake;
	float mDeltaTime;
};