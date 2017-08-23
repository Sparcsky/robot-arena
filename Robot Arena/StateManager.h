#pragma once
#include <SFML\Graphics.hpp>
#include <stack>
#include "GameState.h"

class StateManager
{
public:
	StateManager();
	~StateManager();
	
	void push(GameState * gameState);
	void pop();
	GameState * top();
	void handleEvent(sf::Event & event);
	void update();
	void draw(sf::RenderWindow & window);

private:
	std::stack<GameState*> states;
};

