#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Splash
{
public:
	Splash(Texture &t1, IntRect rect,bool fadeIn,bool fadeOut,float width,float height);
	~Splash();

	void act();
	bool isFinished();
	void draw(RenderWindow &window);

private:
	Sprite sprite_;
	Clock clock;
	float alpha_ = 0.0f,timer_ = 0,delay_ = 1.5;
	bool splashFinished = false;
	bool fadeIn_, fadeOut_;

};

