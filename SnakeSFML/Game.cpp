#include "Game.h"
#include <iostream>

Game::Game()
	: mDeltaTime(0.f)
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
	circle.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);
	sf::Clock clock;

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

		mDeltaTime = clock.restart().asSeconds();

		if (sf::Joystick::isConnected(0))
		{
			float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			std::cout << x << ", " << y << std::endl;

			if (x > 15.f || x < -15.f || y > 15.f || y < -15.f) // Set dead zone
			{
				MoveCircle(x, y, circle);
			}
		}
		mWindow.clear(sf::Color(0, 0, 0));
		mWindow.draw(circle);
		mWindow.display();
	}
}

void Game::MoveCircle(float x, float y, Circle& circle)
{
	int speed = 3;

	if (circle.getPosition().x < 0 && x <= 0)
	{
		circle.move(0, y * mDeltaTime * speed);
	}
	else if (circle.getPosition().x + 2 * circle.getRadius() > GAME_WIDTH && x >= 0)
	{
		circle.move(0, y * mDeltaTime * speed);
	}
	else if (circle.getPosition().y < 0 && y <= 0)
	{
		circle.move(x * mDeltaTime * speed, 0);
	}
	else if (circle.getPosition().y + 2 * circle.getRadius() > GAME_HEIGHT && y >= 0)
	{
		circle.move(x * mDeltaTime * speed, 0);
	}
	else
	{
		circle.move(x * mDeltaTime * speed, y * mDeltaTime * speed);
	}
}
