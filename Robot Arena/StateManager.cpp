#include "StateManager.h"

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
}

void StateManager::push(GameState * gameState)
{
	states.push(gameState);
}

void StateManager::pop()
{
	if (!states.empty())
		states.pop();
}

GameState  *StateManager::top()
{
	return states.top();
}

void StateManager::handleEvent(sf::Event & event)
{
	states.top()->handleEvent(event);
}

void StateManager::update()
{
	states.top()->update();
}

void StateManager::draw(sf::RenderWindow & window)
{
	states.top()->draw(window);
}

