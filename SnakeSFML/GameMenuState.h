#pragma once
#include "IGameState.h"

class Game;

class GameMenuState : public IGameState
{
public:
	virtual void Run(Game& game);
};