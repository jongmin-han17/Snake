#pragma once
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

class GameMenuState;
class GamePlayState;
class Game;

class IGameState
{
public:
	static GameMenuState gameMenu;
	static GamePlayState gamePlay;
	virtual void Run(Game& game) = 0;
};