#pragma once
#include "IGameState.h"
#include "Game.h"

class GameMenuState : public IGameState
{
public:
	virtual void Run(Game& game);
};