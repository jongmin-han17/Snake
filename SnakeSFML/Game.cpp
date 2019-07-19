#include "Game.h"
#include <iostream>

Game::Game()
	: mDeltaTime(0.f)
{
	mSnake.reserve(100);
}

Game::~Game()
{
	for (auto iter = mSnake.begin(); iter != mSnake.end(); iter++)
	{
		delete *iter;
	}
}

bool Game::Init()
{
	mWindow.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Snake", sf::Style::Titlebar | sf::Style::Close);
	mWindow.setFramerateLimit(60);

	Circle* head = new Circle(5.f);
	head->setFillColor(sf::Color(255, 0, 0));
	head->setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);

	Circle* body1 = new Circle(5.f);
	body1->setFillColor(sf::Color(0, 255, 0));
	body1->setPosition(head->getPosition().x, head->getPosition().y + 2 * head->getRadius());

	Circle* body2 = new Circle(5.f);
	body2->setFillColor(sf::Color(0, 255, 0));
	body2->setPosition(body1->getPosition().x, body1->getPosition().y + 2 * body1->getRadius());


	mSnake.push_back(head);
	mSnake.push_back(body1);
	mSnake.push_back(body2);
	return true;
}

void Game::Run()
{
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

			/*
			if (x > 15.f || x < -15.f || y > 15.f || y < -15.f) // Set dead zone
			{
				MoveCircle(x, y, circle);
			}
			*/
		}
		mWindow.clear(sf::Color(0, 0, 0));

		for (size_t i = 0; i < mSnake.size(); i++)
		{
			mWindow.draw(*mSnake[i]);
		}
		mWindow.display();
	}
}

void Game::MoveCircle(float x, float y, Circle& circle)
{
	int speed = 4;

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
