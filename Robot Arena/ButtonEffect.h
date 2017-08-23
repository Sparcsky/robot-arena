#pragma once
#include <SFML\Graphics.hpp>


class ButtonEffect

{
public:
	enum PlayEffect { GROW, SHRINK, NONE };

	ButtonEffect(sf::Sprite & sprite);
	~ButtonEffect();

	void grow(float maxSize);
	void shrink(float minSize);
	bool isFinished();
private:
	sf::Sprite & sprite;
	float increament;
	bool finished = false;
	float scaleX_ = 0.0f, scaleY_ = 0.0f;
};




