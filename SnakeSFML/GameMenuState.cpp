#include "GameMenuState.h"
#include "Game.h"

GameMenuState::GameMenuState()
{
	// Initialize Start Button.
	if (!mStartButtonTexture.loadFromFile("resources/startButton.png"))
	{
		std::cout << "Cannot load image.\n";
		return;
	}

	mStartButton.setTexture(mStartButtonTexture);
	mStartButton.setPosition(565, 380);

	if (!mQuitButtonTexture.loadFromFile("resources/quitButton.png"))
	{
		std::cout << "Cannot load image.\n";
		return;
	}

	mQuitButton.setTexture(mQuitButtonTexture);
	mQuitButton.setPosition(565, 440);
}

void GameMenuState::Run(Game& game)
{
	game.GetWindow().clear(sf::Color(0, 0, 0));
	// Draw the pause message
	game.GetWindow().draw(game.GetPauseMessage());
	game.GetWindow().draw(mStartButton);
	game.GetWindow().draw(mQuitButton);
	game.GetWindow().display();
}
