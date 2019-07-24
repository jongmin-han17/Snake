#include "GameMenuState.h"

void GameMenuState::Run(Game & game)
{
	mWindow.clear(sf::Color(0, 0, 0));
	// Draw the pause message
	mWindow.draw(mPauseMessage);
	mWindow.display();
}
