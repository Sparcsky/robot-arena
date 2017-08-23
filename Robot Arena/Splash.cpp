#include "Splash.h"

Splash::Splash(Texture &texture, IntRect rect, bool fadeIn, bool fadeOut, float width, float height)
	:fadeIn_(fadeIn), fadeOut_(fadeOut)
{

	float w = width / rect.width;
	float h = height / rect.height;

	sprite_.setColor(Color(255, 255, 255, alpha_));
	sprite_.setTexture(texture);
	sprite_.setTextureRect(rect);
	sprite_.setScale(w, h);

}
Splash::~Splash()
{
}

void Splash::act()
{
	timer_ += clock.restart().asSeconds();
	if (timer_ > delay_)
	{
		delay_ = 0.005f;
		timer_ = 0;
		if (fadeIn_)
		{
			alpha_ += 2.0f * .55f;

			if (alpha_ >= 255)
			{
				fadeIn_ = false;
				delay_ = 2.5f;
			}
		}

		else if (!fadeIn_ && fadeOut_)
		{
			alpha_ -= 2.0f * .55f;
			if (alpha_ <= 0)
			{
				delay_ = 2.5f;
				fadeIn_ = true;
				splashFinished = true;
			}
		}
		sprite_.setColor(Color(255, 255, 255, alpha_));
	}
}

bool Splash::isFinished()
{
	return splashFinished;
}

void Splash::draw(RenderWindow & window)
{
	window.draw(sprite_);
}

