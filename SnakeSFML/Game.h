#pragma once
#include "Circle.h"
#include "eState.h"
#include <vector>
#include <cmath>

class Game
{
public:
	Game();
	virtual ~Game();
	bool Init();
	void Run();
	void MoveSnake(float x, float y);
	float GetDistance(sf::Vector2f point1, sf::Vector2f point2);
	float GetCOS(sf::Vector2f point1, sf::Vector2f point2);
	float GetSIN(sf::Vector2f point1, sf::Vector2f point2);
	void DetectFoodCollision();
	void DetectPoisonCollision();
private:
	const int GAME_WIDTH = 1280;
	const int GAME_HEIGHT = 720;
	sf::RenderWindow mWindow;
	std::vector<Circle*> mSnake;
	std::vector<Circle*> mFood;
	std::vector<Circle*> mPoison;
	float mDeltaTime;
	float mRadius;
	sf::Font mFont;
	sf::Text mPauseMessage;
	eState mGameState;
};