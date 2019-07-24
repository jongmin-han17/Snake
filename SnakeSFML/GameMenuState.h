#pragma once
#include "IGameState.h"

class GameMenuState : public IGameState
{
public:
	virtual void Run(Game& game);
};