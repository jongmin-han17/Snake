#include "GamePlayState.h"
#include "Game.h"

void GamePlayState::Run(Game& game)
{
	if (rand() % 200 == 0)  // Create food
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

	if (rand() % 500 == 0) // Create poisoned food
	{
		Circle* poison = new Circle(mRadius);
		poison->setPosition(static_cast<float>(rand() % (GAME_WIDTH - static_cast<int>(mRadius))), static_cast<float>(rand() % (GAME_HEIGHT - static_cast<int>(mRadius))));
		poison->setFillColor(sf::Color(255, 0, 0)); // Set poisoned food color red
		std::cout << "Poisoned Food(" << poison << ") created!\n";
		if (mPoison.empty())
		{
			mPoison.push_back(poison);
		}
		else
		{
			bool bNullFound = false;
			size_t size = mPoison.size();
			for (size_t i = 0; i < size; i++) // Check empty index to save memory
			{
				if (mPoison[i] == nullptr)
				{
					mPoison[i] = poison;
					bNullFound = true;
					break;
				}
			}

			if (!bNullFound)
			{
				mPoison.push_back(poison);
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
			MoveSnake(x, y);
			DetectFoodCollision();
			DetectPoisonCollision();
		}
		else
		{
			int speed = 30;
			// cos@ = delta x / 2r
			// sin@ = delta y / 2r
			// MoveSnake(speed * cos@, speed * sin@)
			MoveSnake(speed * (mSnake[0]->GetCenterPosition().x - mSnake[1]->GetCenterPosition().x) / (2 * mRadius),
				speed * (mSnake[0]->GetCenterPosition().y - mSnake[1]->GetCenterPosition().y) / (2 * mRadius));
			DetectFoodCollision();
			DetectPoisonCollision();
		}
	}
	mWindow.clear(sf::Color(0, 0, 0));
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

	for (size_t i = 0; i < mPoison.size(); i++)
	{
		if (mPoison[i] != nullptr)
		{
			mWindow.draw(*mPoison[i]);
		}
	}
	mWindow.display();
}
