#include "GameMenuState.h"

void GameMenuState::Run(Game& game)
{
	sf::Clock clock;
	srand(static_cast<unsigned int>(time(0)));

	while (mWindow.isOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				mWindow.close();
				break;
			}

			// Press button A to start the game
			if (event.type == sf::Event::JoystickButtonPressed && sf::Joystick::isButtonPressed(0, 0))
			{
				if (mGameState == STATE_GAMEOVER)
				{
					for (auto iter = mSnake.begin(); iter != mSnake.end(); iter++)  // Destroy snake
					{
						delete *iter;
					}
					mSnake.clear();

					for (auto iter = mFood.begin(); iter != mFood.end(); iter++) // Destroy foods
					{
						if (*iter != nullptr)
						{
							delete *iter;
						}
					}
					mFood.clear();

					for (auto iter = mPoison.begin(); iter != mPoison.end(); iter++) // Destroy poisoned foods
					{
						if (*iter != nullptr)
						{
							delete *iter;
						}
					}
					mPoison.clear();

					Init();
				}
				mGameState = STATE_PLAY;
			}
		}

		mWindow.clear(sf::Color(0, 0, 0));
		// Draw the pause message
		mWindow.draw(mPauseMessage);
		mWindow.display();
	}
}
