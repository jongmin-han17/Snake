#pragma once

class Game;

class IGameState
{
public:
	static GameMenuState gameMenu;
	virtual void Run(Game& game) = 0;
};