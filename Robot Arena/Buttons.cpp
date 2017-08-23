#include "Buttons.h"
Buttons::Buttons(Texture &texture,IntRect rect)
{
	sprite_.setTexture(texture);
	sprite_.setTextureRect(rect);
	sprite_.setOrigin(getWidth() / 2, getHeight() / 2);
	sprite_.setScale(.25f, .25f);
	buttonEffect = new ButtonEffect(sprite_);
	playEffect = ButtonEffect::NONE;
}

Buttons::~Buttons()
{
	delete buttonEffect;
}

bool Buttons::isOver(Vector2f mouse)
{
	return mouse.x > sprite_.getGlobalBounds().left && mouse.x < sprite_.getGlobalBounds().left + sprite_.getGlobalBounds().width
		&& mouse.y > sprite_.getGlobalBounds().top && mouse.y < sprite_.getGlobalBounds().top + sprite_.getGlobalBounds().height;
}
bool Buttons::isClicked(Vector2f mouse)
{
	if (isOver(mouse)) {
		setAnimation(ButtonEffect::GROW);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;
	}
	else setAnimation(ButtonEffect::SHRINK);
	return false;
}

void Buttons::actAnimation()
{
	switch (playEffect) {
	case ButtonEffect::PlayEffect::NONE:   break;
	case ButtonEffect::PlayEffect::GROW:   buttonEffect->grow(0.55f); break;
	case ButtonEffect::PlayEffect::SHRINK: buttonEffect->shrink(0.20f); break;
	}
}

void Buttons::setAnimation(ButtonEffect::PlayEffect playEffect)
{
	this->playEffect = playEffect;
}
void Buttons::setSize(float width, float height)
{
	float w = width / sprite_.getGlobalBounds().width;
	float h = height / sprite_.getGlobalBounds().height;
	sprite_.scale(w, h);
}

void Buttons::setPosition(float x, float y)
{
	sprite_.setPosition(x, y);
}

void Buttons::draw(RenderWindow & window)
{
	window.draw(sprite_);
}

float Buttons::getWidth()
{
	return sprite_.getGlobalBounds().width;
}

float Buttons::getHeight()
{
	return sprite_.getGlobalBounds().height;

}
