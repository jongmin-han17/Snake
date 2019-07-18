#include "Game.h"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

bool Game::Init()
{
	mWindow.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Snake", sf::Style::Titlebar | sf::Style::Close);
	mWindow.setFramerateLimit(60);
	return true;
}

void Game::Run()
{
	Circle circle(5.f);
	circle.setFillColor(sf::Color(255, 0, 0));
	circle.setPosition(10, 0);

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
		}

		if (sf::Joystick::isConnected(0))
		{
			float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			std::cout << x << ", " << y << std::endl;

			if (x > 15.f || x < -15.f || y > 15.f || y < -15.f)
			{
				circle.move(x, y);
			}
		}

		mWindow.clear(sf::Color(0, 0, 0));
		mWindow.draw(circle);
		mWindow.display();
	}
}
