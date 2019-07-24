#pragma once

class Game;

class IGameState
{
public:
	virtual void Run(Game& game) = 0;
};