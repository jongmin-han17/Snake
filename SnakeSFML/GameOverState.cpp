#include "GameOverState.h"
#include "Game.h"

void GameOverState::Run(Game& game)
{
	for (auto iter = game.GetSnake().begin(); iter != game.GetSnake().end(); iter++)  // Destroy snake
	{
		delete *iter;
	}
	game.GetSnake().clear();

	for (auto iter = game.GetFood().begin(); iter != game.GetFood().end(); iter++) // Destroy foods
	{
		if (*iter != nullptr)
		{
			delete *iter;
		}
	}
	game.GetFood().clear();

	for (auto iter = game.GetPoison().begin(); iter != game.GetPoison().end(); iter++) // Destroy poisoned foods
	{
		if (*iter != nullptr)
		{
			delete *iter;
		}
	}
	game.GetPoison().clear();


	game.GetPauseMessage().setString("GAME OVER\nPress A to restart the game");
	game.GetWindow().clear(sf::Color(0, 0, 0));
	// Draw the pause message
	game.GetWindow().draw(game.GetPauseMessage());
	game.GetWindow().display();
}