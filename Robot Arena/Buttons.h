#pragma once
#include <SFML\Graphics.hpp>
#include "ButtonEffect.h"

using namespace sf;

class Buttons
{
public:
	ButtonEffect * buttonEffect;

	Buttons(Texture &texture,IntRect rect);
	~Buttons();

	bool isOver(Vector2f mouse);
	bool isClicked(Vector2f mouse);

	void actAnimation();
	void setAnimation(ButtonEffect::PlayEffect playEffect);
	void setSize(float width, float height);
	void setPosition(float x, float y);
	void draw(RenderWindow & window);

	float getWidth();
	float getHeight();

protected:
	Sprite sprite_;
	const float defaultSize_ = sprite_.getScale().x;
	ButtonEffect::PlayEffect playEffect;
};

