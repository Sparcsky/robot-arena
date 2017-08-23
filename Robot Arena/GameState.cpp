#include "GameState.h"
#include "Game.h"

GameState::GameState(Game & game) :game_(game)
{
	
}
GameState::~GameState()
{
}

void GameState::handleEvent(Event & event)
{
}

void GameState::update()
{
	mousePos = game_.window->mapPixelToCoords(Mouse::getPosition(*game_.window));
	cursor.setPosition(mousePos);
	cursor.update();
}

void GameState::draw(RenderWindow & window)
{
	cursor.draw(window);
}
