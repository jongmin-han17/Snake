#include "GameMenuState.h"

void GameMenuState::Run(Game& game)
{
	sf::Clock clock;
	srand(static_cast<unsigned int>(time(0)));

	while (game.GetWindow().isOpen())
	{
		sf::Event event;
		while (game.GetWindow().pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				game.GetWindow().close();
				break;
			}

			// Press button A to start the game
			if (event.type == sf::Event::JoystickButtonPressed && sf::Joystick::isButtonPressed(0, 0))
			{
			}
		}

		game.GetWindow().clear(sf::Color(0, 0, 0));
		// Draw the pause message
		game.GetWindow().draw(game.GetPauseMessage());
		game.GetWindow().display();
	}
}
