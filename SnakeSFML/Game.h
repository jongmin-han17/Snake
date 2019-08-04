#pragma once
#include "Circle.h"
#include <vector>
#include <cmath>
#include <iostream>
#include "GameMenuState.h"
#include "GamePlayState.h"
#include "GameOverState.h"

class Game
{
	friend class GameMenuState;
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
	sf::RenderWindow& GetWindow();
	sf::Text& GetPauseMessage();
	float GetRadius();
	std::vector<Circle*>& GetSnake();
	std::vector<Circle*>& GetFood();
	std::vector<Circle*>& GetPoison();
	void SetDeltaTime(float deltaTime);
	sf::Clock& GetClock();
private:
	sf::RenderWindow mWindow;
	std::vector<Circle*> mSnake;
	std::vector<Circle*> mFood;
	std::vector<Circle*> mPoison;
	float mDeltaTime;
	float mRadius;
	sf::Font mFont;
	sf::Text mPauseMessage;
	sf::Clock mClock;
	IGameState* mState;
	GameMenuState mGameMenuState;
	GameOverState mGameOverState;
	GamePlayState mGamePlayState;
};