#pragma once
#include "IGameState.h"

class GamePlayState : public IGameState
{
public:
	void Run(Game& game);
};