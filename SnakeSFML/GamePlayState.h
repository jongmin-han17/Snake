#pragma once
#include "IGameState.h"

class GamePlayState : public IGameState
{
public:
	GamePlayState(Game& game);
	void Run(Game& game);
};