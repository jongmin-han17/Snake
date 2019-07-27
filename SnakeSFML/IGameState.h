#pragma once
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Global.h"

class Game;

class IGameState // Game State Interface
{
public:
	virtual void Run(Game& game) = 0; // Pure virtual function
};