#include "GameMenuState.h"
#include "Game.h"

GameMenuState::GameMenuState()
	: mButtonFocus(START)
{
	// Initialize Start Button.
	if (!mStartButtonTexture.loadFromFile("resources/startButton.png"))
	{
		std::cout << "Cannot load image.\n";
		return;
	}

	if (!mQuitButtonTexture.loadFromFile("resources/quitButton.png"))
	{
		std::cout << "Cannot load image.\n";
		return;
	}


	if (!mGameTitleTexture.loadFromFile("resources/gameTitle.png"))
	{
		std::cout << "Cannot load image.\n";
		return;
	}
	
	if (!mStartButtonFocusTexture.loadFromFile("resources/startButtonFocus.png"))
	{
		std::cout << "Cannot load image.\n";
		return;
	}

	if (!mQuitButtonFocusTexture.loadFromFile("resources/quitButtonFocus.png"))
	{
		std::cout << "Cannot load image.\n";
		return;
	}

	mGameTitle.setTexture(mGameTitleTexture);
	mGameTitle.setPosition(450, 200);

	mStartButton.setTexture(mStartButtonFocusTexture);
	mStartButton.setPosition(565, 380);

	mQuitButton.setTexture(mQuitButtonTexture);
	mQuitButton.setPosition(565, 440);
}

void GameMenuState::Run(Game& game)
{

	if (sf::Joystick::isConnected(0))
	{
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

		if (y > 20.f) // Set dead zone
		{
			if (mButtonFocus == START)
			{
				mButtonFocus = QUIT;
				mStartButton.setTexture(mStartButtonTexture);
				mQuitButton.setTexture(mQuitButtonFocusTexture);
			}
		}

		if (y < -20.f) // Set dead zone
		{
			if (mButtonFocus == QUIT)
			{
				mButtonFocus = START;
				mStartButton.setTexture(mStartButtonFocusTexture);
				mQuitButton.setTexture(mQuitButtonTexture);
			}
		}
	}

	game.GetWindow().clear(sf::Color(0, 0, 0));
	game.GetWindow().draw(mGameTitle);
	game.GetWindow().draw(mStartButton);
	game.GetWindow().draw(mQuitButton);
	game.GetWindow().display();
}
