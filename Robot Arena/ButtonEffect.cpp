#include "ButtonEffect.h"
#include <iostream>
ButtonEffect::ButtonEffect(sf::Sprite & sprite) :sprite(sprite)
{
}

ButtonEffect::~ButtonEffect()
{
}

void ButtonEffect::grow(float maxSize)
{
	if (scaleX_ < maxSize && scaleY_ < maxSize) {
		scaleX_ = sprite.getScale().x * 1.15f;
		scaleY_ = sprite.getScale().y * 1.15f;
		sprite.setScale(scaleX_,scaleY_);
	}
}

void ButtonEffect::shrink(float minSize)
{

	if (scaleX_ > minSize && scaleY_ > minSize) {
		scaleX_ = sprite.getScale().x / 1.15f;
		scaleY_ = sprite.getScale().y / 1.15f;
		sprite.setScale(scaleX_, scaleY_);
	}
}

bool ButtonEffect::isFinished()
{
	return finished;
}
