#pragma once
#include "IGameState.h"
#include "eButtonFocus.h"

class GameMenuState : public IGameState
{
public:
	GameMenuState();
	virtual ~GameMenuState() = default;
	void Run(Game& game);
private:
	sf::Sprite mGameTitle;
	sf::Sprite mStartButton;
	sf::Sprite mQuitButton;
	sf::Texture mStartButtonTexture;
	sf::Texture mQuitButtonTexture;
	sf::Texture mGameTitleTexture;
	sf::Texture mQuitButtonFocusTexture;
	sf::Texture mStartButtonFocusTexture;
	eButtonFocus mButtonFocus;
};