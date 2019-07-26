#include "GameMenuState.h"
#include "Game.h"

void GameMenuState::Run(Game& game)
{
	game.GetWindow().clear(sf::Color(0, 0, 0));
	// Draw the pause message
	game.GetWindow().draw(game.GetPauseMessage());
	game.GetWindow().display();
}
