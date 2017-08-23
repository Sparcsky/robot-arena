#include "Entity.h"

Entity::~Entity()
{
}

void Entity::draw(RenderWindow & window)
{
	window.draw(sprite);
}

void Entity::setPosition(Vector2f position)
{
	sprite.setPosition(position);
}

int Entity::getWidth()
{
	return sprite.getGlobalBounds().width;
}

int Entity::getHeight()
{
	return sprite.getGlobalBounds().height;
}

void Entity::scale(float scaleX,float scaleY)
{
	sprite.setScale(scaleX,scaleY);
}

Vector2f Entity::getPosition()
{
	return sprite.getPosition();
}
