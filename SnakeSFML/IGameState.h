#pragma once
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Global.h"

class Game;

class IGameState
{
public:
	virtual void Run(Game& game) = 0;
};