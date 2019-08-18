#pragma once
#include "IGameState.h"

// 게임 오버 상태 클래스
class GameOverState : public IGameState
{
public:
	void Run(Game& game);
};