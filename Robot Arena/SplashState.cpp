#include "SplashState.h"

SplashState::SplashState(Game & game)
	: GameState(game)
{

	atlas.reset(new TextureAtlas("assets/sprites/splash.png", "assets/data/splash_data.txt"));

	stacks.push(Splash(atlas->getTexture(), atlas.get()->getImage("geekboy"), true, true, game_.width_, game_.height_));
	stacks.push(Splash(atlas->getTexture(), atlas.get()->getImage("robothead"), true, true, game_.width_, game_.height_));
}

SplashState::~SplashState()
{
	delete texture;
}

void SplashState::handleEvent(Event & event)
{

}
void SplashState::update()
{
	if (!stacks.empty())
	{
		stacks.top().act();

		if (stacks.top().isFinished()) {
			stacks.pop();
		}
	}
	else {
		game_.stateManager->push(new MenuState(game_));
	}
}

void SplashState::draw(RenderWindow & window)
{
	if (!stacks.empty())
		stacks.top().draw(window);
}
