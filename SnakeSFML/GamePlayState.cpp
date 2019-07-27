#include "GamePlayState.h"
#include "Game.h"

void GamePlayState::Run(Game& game)
{
	if (rand() % 200 == 0)  // Create food
	{
		Circle* food = new Circle(game.GetRadius());
		food->setPosition(static_cast<float>(rand() % (GAME_WIDTH - static_cast<int>(game.GetRadius()))), static_cast<float>(rand() % (GAME_HEIGHT - static_cast<int>(game.GetRadius()))));
		food->setFillColor(sf::Color(0, 0, 255));
		std::cout << "Food(" << food << ") created!\n";
		if (game.GetFood().empty())
		{
			game.GetFood().push_back(food);
		}
		else
		{
			bool bNullFound = false;
			size_t size = game.GetFood().size();
			for (size_t i = 0; i < size; i++) // Check empty index to save memory
			{
				if (game.GetFood()[i] == nullptr)
				{
					game.GetFood()[i] = food;
					bNullFound = true;
					break;
				}
			}

			if (!bNullFound)
			{
				game.GetFood().push_back(food);
			}
		}
	}

	if (rand() % 500 == 0) // Create poisoned food
	{
		Circle* poison = new Circle(game.GetRadius());
		poison->setPosition(static_cast<float>(rand() % (GAME_WIDTH - static_cast<int>(game.GetRadius()))), static_cast<float>(rand() % (GAME_HEIGHT - static_cast<int>(game.GetRadius()))));
		poison->setFillColor(sf::Color(255, 0, 0)); // Set poisoned food color red
		std::cout << "Poisoned Food(" << poison << ") created!\n";
		if (game.GetPoison().empty())
		{
			game.GetPoison().push_back(poison);
		}
		else
		{
			bool bNullFound = false;
			size_t size = game.GetPoison().size();
			for (size_t i = 0; i < size; i++) // Check empty index to save memory
			{
				if (game.GetPoison()[i] == nullptr)
				{
					game.GetPoison()[i] = poison;
					bNullFound = true;
					break;
				}
			}

			if (!bNullFound)
			{
				game.GetPoison().push_back(poison);
			}
		}
	}

	game.SetDeltaTime(game.GetClock().restart().asSeconds());
	
	if (sf::Joystick::isConnected(0))
	{
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);


		if (x > 15.f || x < -15.f || y > 15.f || y < -15.f) // Set dead zone
		{
			game.MoveSnake(x, y);
			game.DetectFoodCollision();
			game.DetectPoisonCollision();
		}
		else
		{
			int speed = 30;
			// cos@ = delta x / 2r
			// sin@ = delta y / 2r
			// MoveSnake(speed * cos@, speed * sin@)
			game.MoveSnake(speed * (game.GetSnake()[0]->GetCenterPosition().x - game.GetSnake()[1]->GetCenterPosition().x) / (2 * game.GetRadius()),
				speed * (game.GetSnake()[0]->GetCenterPosition().y - game.GetSnake()[1]->GetCenterPosition().y) / (2 * game.GetRadius()));
			game.DetectFoodCollision();
			game.DetectPoisonCollision();
		}
	}
	game.GetWindow().clear(sf::Color(0, 0, 0));
	for (size_t i = 0; i < game.GetSnake().size(); i++)
	{
		game.GetWindow().draw(*game.GetSnake()[i]);
	}

	for (size_t i = 0; i < game.GetFood().size(); i++)
	{
		if (game.GetFood()[i] != nullptr)
		{
			game.GetWindow().draw(*game.GetFood()[i]);
		}
	}

	for (size_t i = 0; i < game.GetPoison().size(); i++)
	{
		if (game.GetPoison()[i] != nullptr)
		{
			game.GetWindow().draw(*game.GetPoison()[i]);
		}
	}
	game.GetWindow().display();
}
