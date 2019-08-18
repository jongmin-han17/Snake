// Copyright © 2019 Jongmin Han
// Email: jongmin.han17@gmail.com
// github: github.com/jongminHan
#include "Game.h"

int main()
{
	// 게임 오브젝트 생성
	Game* game = new Game();

	// 게임 초기화 후 게임 실행
	if (game->Init())
	{
		game->Run();
	}

	// 게임 오브젝트 삭제
	delete game;

	return 0;
}