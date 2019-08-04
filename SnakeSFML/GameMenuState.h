#pragma once
#include "IGameState.h"

class GameMenuState : public IGameState
{
public:
	GameMenuState();
	virtual ~GameMenuState() = default;
	void Run(Game& game);
private:
	sf::Sprite mStartButton;
	sf::Sprite mQuitButton;
	sf::Texture mStartButtonTexture;
	sf::Texture mQuitButtonTexture;
};