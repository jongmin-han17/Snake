#pragma once
#include "IGameState.h"

class GamePlayState : public IGameState
{
public:
	GamePlayState();
	void Run(Game& game);
	void SetIsJoystickSignalDetected(bool enabled);
private:
	bool mbJoystickSignalDetected;
};