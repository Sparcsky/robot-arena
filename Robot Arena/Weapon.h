#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
using namespace sf;

class Weapon :Entity
{
public:
	Weapon();
	~Weapon();

	virtual void setPosition(Vector2f position);
	virtual void draw(RenderWindow & window);
	virtual void update();

	virtual int getWidth() ;
	virtual int getHeight() ;
	virtual Vector2f  getPosition() ;
private:
};

