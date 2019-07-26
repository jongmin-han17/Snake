#pragma once
#include "IGameState.h"

class GamePlayState : public IGameState
{
public:
	virtual void Run(Game& game);
};