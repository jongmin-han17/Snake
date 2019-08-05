#include "GameOverState.h"
#include "Game.h"

void GameOverState::Run(Game& game)
{
	for (auto iter = game.mSnake.begin(); iter != game.mSnake.end(); iter++)  // Destroy snake
	{
		delete *iter;
	}
	game.mSnake.clear();

	for (auto iter = game.mFood.begin(); iter != game.mFood.end(); iter++) // Destroy foods
	{
		if (*iter != nullptr)
		{
			delete *iter;
		}
	}
	game.mFood.clear();

	for (auto iter = game.mPoison.begin(); iter != game.mPoison.end(); iter++) // Destroy poisoned foods
	{
		if (*iter != nullptr)
		{
			delete *iter;
		}
	}
	game.mPoison.clear();


	game.mPauseMessage.setString("GAME OVER\nPress A to restart the game");
	game.mWindow.clear(sf::Color(0, 0, 0));
	// Draw the pause message
	game.mWindow.draw(game.mPauseMessage);
	game.mWindow.display();
}