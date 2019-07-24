#pragma once
#include "IGameState.h"
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

class GameMenuState : public IGameState
{
public:
	virtual void Run(Game& game);
};