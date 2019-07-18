#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::Init()
{
	mWindow.create(sf::VideoMode(1280, 720), "Snake", sf::Style::Titlebar | sf::Style::Close);
	mWindow.setFramerateLimit(60);

	return true;
}

void Game::Run()
{
}
