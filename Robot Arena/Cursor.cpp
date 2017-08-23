#include "Cursor.h"

Cursor::Cursor()
{
	texture.reset(new Texture());
	if (texture->loadFromFile("assets/sprites/crosshair.png")) EXIT_FAILURE;

	sprite.setTexture(*texture);
	sprite.setScale(0.15, 0.15);
	sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
	sprite.setColor(Color(255, 255, 255, 150));
}

Cursor::~Cursor()
{
}

void Cursor::update()
{
	sprite.rotate(1);

	if (cursorScale < .2f && isMinScale) {
		cursorScale += .0005f;
	}
	else isMinScale = false;
	if (!isMinScale) {
		cursorScale -= .0005f;
		if (cursorScale < .15f) isMinScale = true;
	}
	sprite.setScale(cursorScale, cursorScale);
}
