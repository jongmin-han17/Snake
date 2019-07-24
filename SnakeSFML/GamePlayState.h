#pragma once
#include "IGameState.h"

class GamePlayState : public IGameState
{
	virtual void Run(Game& game);
};