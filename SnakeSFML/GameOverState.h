#pragma once
#include "IGameState.h"

class GameOverState : public IGameState
{
public:
	void Run(Game& game);
};