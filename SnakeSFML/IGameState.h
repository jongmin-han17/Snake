#pragma once
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Game.h"

class GameMenuState;
class GamePlayState;

class IGameState
{
public:
	static GameMenuState gameMenu;
	static GamePlayState gamePlay;
	virtual void Run(Game& game) = 0;
};