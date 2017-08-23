#pragma once
#include <memory>
#include "Entity.h"

class Cursor: public Entity
{
public:
	Cursor();
	~Cursor();

	virtual void update();

private:
	std::unique_ptr<sf::Texture> texture;
	float cursorScale = .15f;
	bool isMinScale = true;
};

