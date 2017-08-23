#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Entity
{
public:
	virtual ~Entity();
	virtual void update() = 0;

	virtual void draw(RenderWindow & window);

	virtual void setPosition(Vector2f position);
	virtual int getWidth();
	virtual int getHeight();
	virtual void scale(float scaleX, float scaleY);

	virtual Vector2f  getPosition();

protected:
	Sprite sprite;
};

