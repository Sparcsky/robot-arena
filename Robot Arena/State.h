#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class State
{
public:
	virtual ~State();
	virtual void handleEvent(Event & event) = 0;
	virtual void update() = 0;
	virtual void draw(RenderWindow & window) = 0;
};

