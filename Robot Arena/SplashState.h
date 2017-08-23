#pragma once
#include <stack>
#include "Splash.h"
#include "Game.h"
#include "MenuState.h"


class SplashState : public GameState
{
public:
	SplashState(Game & game);
	~SplashState();

	void handleEvent(Event & event) override;
	void update() override;
	void draw(RenderWindow & window) override;
private:
	Texture * texture;
	stack<Splash> stacks;
};

