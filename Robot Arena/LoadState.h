#pragma once
#include "GameState.h"
class LoadState :
	public GameState
{
public:
	LoadState(Game & game);
	~LoadState();

	void loadAssets();



};

