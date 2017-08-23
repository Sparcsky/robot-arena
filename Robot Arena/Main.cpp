#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Game.h"
int main()
{
	Game game;
	game.initialize();
	game.run();

	_CrtDumpMemoryLeaks();

	return 0;
}