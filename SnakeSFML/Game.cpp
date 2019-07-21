#include "Game.h"
#include <iostream>
#include <cmath>

Game::Game()
	: mDeltaTime(0.f)
	, mRadius(5.f)
	, mbIsPlaying(false)
{
	mSnake.reserve(100);
	mFood.reserve(100);
}

Game::~Game()
{
	for (auto iter = mSnake.begin(); iter != mSnake.end(); iter++)  // Destroy snake
	{
		delete *iter;
	}

	for (auto iter = mFood.begin(); iter != mFood.end(); iter++) // Destroy foods
	{
		if (*iter != nullptr)
		{
			delete *iter;
		}
	}
}

bool Game::Init()
{
	mWindow.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Snake", sf::Style::Titlebar | sf::Style::Close);
	mWindow.setFramerateLimit(60);

	Circle* head = new Circle(mRadius);
	head->setFillColor(sf::Color(145, 2, 247));
	head->setPosition(static_cast<float>(GAME_WIDTH) / 2.f, static_cast<float>(GAME_HEIGHT) / 2.f);

	Circle* body1 = new Circle(mRadius);
	body1->setFillColor(sf::Color(0, 255, 0));
	body1->setPosition(head->getPosition().x, head->getPosition().y + 2 * mRadius);

	Circle* body2 = new Circle(mRadius);
	body2->setFillColor(sf::Color(0, 255, 0));
	body2->setPosition(body1->getPosition().x, body1->getPosition().y + 2 * mRadius);

	mSnake.push_back(head);
	mSnake.push_back(body1);
	mSnake.push_back(body2);

	// Load the text font
	if (!mFont.loadFromFile("C:/Users/Jongmin/source/repos/SnakeSFML/SnakeSFML/resources/sansation.ttf"))
	{
		std::cout << "Failed to initialize the game\n";
		return false;
	}

	// Initialize the pause message
	mPauseMessage.setFont(mFont);
	mPauseMessage.setCharacterSize(40);
	mPauseMessage.setPosition(170.f, 150.f);
	mPauseMessage.setFillColor(sf::Color::White);
	mPauseMessage.setString("Welcome to Snake!\nPress A to start the game");

	return true;
}

void Game::Run()
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
				mbIsPlaying = true;
			}
		}

		

		if (mbIsPlaying)
		{
			if (rand() % 200 == 0)
			{
				Circle* food = new Circle(mRadius);
				food->setPosition(static_cast<float>(rand() % (GAME_WIDTH - static_cast<int>(mRadius))), static_cast<float>(rand() % (GAME_HEIGHT - static_cast<int>(mRadius))));
				food->setFillColor(sf::Color(0, 0, 255));
				std::cout << "Food(" << food << ") created!\n";
				if (mFood.empty())
				{
					mFood.push_back(food);
				}
				else
				{
					bool bNullFound = false;
					size_t size = mFood.size();
					for (size_t i = 0; i < size; i++) // Check empty index to save memory
					{
						if (mFood[i] == nullptr)
						{
							mFood[i] = food;
							bNullFound = true;
							break;
						}
					}

					if (!bNullFound)
					{
						mFood.push_back(food);
					}
				}
			}

			mDeltaTime = clock.restart().asSeconds();

			if (sf::Joystick::isConnected(0))
			{
				float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
				float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);


				if (x > 15.f || x < -15.f || y > 15.f || y < -15.f) // Set dead zone
				{
					std::cout << "(" << x << ", " << y << ")\n";

					MoveSnake(x, y);
					DetectFoodCollision();
				}
				else
				{
					int speed = 30;
					// cos@ = delta x / 2r
					// sin@ = deta y / 2r
					// MoveSnake(speed * cos@, speed * sin@)
					MoveSnake(speed * (mSnake[0]->GetCenterPosition().x - mSnake[1]->GetCenterPosition().x) / (2 * mRadius), 
						speed * (mSnake[0]->GetCenterPosition().y - mSnake[1]->GetCenterPosition().y) / (2 * mRadius));
					DetectFoodCollision();
				}
			}
		}


		mWindow.clear(sf::Color(0, 0, 0));
		if (mbIsPlaying)
		{
			for (size_t i = 0; i < mSnake.size(); i++)
			{
				mWindow.draw(*mSnake[i]);
			}

			for (size_t i = 0; i < mFood.size(); i++)
			{
				if (mFood[i] != nullptr)
				{
					mWindow.draw(*mFood[i]);
				}
			}
		}
		else
		{
			// Draw the pause message
			mWindow.draw(mPauseMessage);
		}

		mWindow.display();
	}
}

void Game::MoveSnake(float x, float y)
{
	int speed = 4;
	int size = static_cast<int>(mSnake.size());

	for (int i = 0; i < size; i++)
	{
		if (i == 0) // Move head
		{
			if (mSnake[i]->getPosition().x < 0 && x <= 0)
			{
				mSnake[i]->move(0, y * mDeltaTime * speed);
			}
			else if (mSnake[i]->getPosition().x + 2 * mSnake[i]->getRadius() > GAME_WIDTH && x >= 0)
			{
				mSnake[i]->move(0, y * mDeltaTime * speed);
			}
			else if (mSnake[i]->getPosition().y < 0 && y <= 0)
			{
				mSnake[i]->move(x * mDeltaTime * speed, 0);
			}
			else if (mSnake[i]->getPosition().y + 2 * mSnake[i]->getRadius() > GAME_HEIGHT && y >= 0)
			{
				mSnake[i]->move(x * mDeltaTime * speed, 0);
			}
			else
			{
				mSnake[i]->move(x * mDeltaTime * speed, y * mDeltaTime * speed);
			}
		}
		else  // Move body
		{
			// (x - 2rcos@, y + 2rsin@)
			float x = mSnake[i - 1]->getPosition().x;
			float y = mSnake[i - 1]->getPosition().y;
			float r = mRadius;
			float cos = GetCOS(mSnake[i - 1]->getPosition(), mSnake[i]->getPosition());
			float sin = GetSIN(mSnake[i - 1]->getPosition(), mSnake[i]->getPosition());

			mSnake[i]->setPosition(x - 2 * r * cos, y + 2 * r * sin);
		}
	}
}

float Game::GetDistance(sf::Vector2f point1, sf::Vector2f point2)
{
	return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));  // Pythagorean theorem
}

float Game::GetCOS(sf::Vector2f point1, sf::Vector2f point2)
{
	return (point1.x - point2.x) / GetDistance(point1, point2);
}

float Game::GetSIN(sf::Vector2f point1, sf::Vector2f point2)
{
	return (point2.y - point1.y) / GetDistance(point1, point2);
}

void Game::DetectFoodCollision()
{
	for (size_t i = 0; i < mFood.size(); i++)
	{
		if (mFood[i] != nullptr)
		{
			if (GetDistance(mFood[i]->GetCenterPosition(), mSnake[0]->GetCenterPosition()) <= 2 * mRadius)
			{
				std::cout << "Food(" << mFood[i] << ") destroyed\n";
				delete mFood[i];
				mFood[i] = nullptr;

				Circle* body = new Circle(mRadius);
				body->setFillColor(sf::Color(0, 255, 0));
				body->setPosition(-10, -10);
				mSnake.push_back(body);
				break;
			}
		}
	}
}
