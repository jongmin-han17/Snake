#pragma once
#include "IGameState.h"

class GameMenuState : public IGameState
{
public:
	void Run(Game& game);
};