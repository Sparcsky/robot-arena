#include "Player.h"

Player::Player(Animation &animation, Vector2f position)
	:Robot(animation, position)
{
	animation_.setSprite(sprite);
	speed_ = 2;
}

Player::~Player()
{
}

std::unique_ptr<Robot> Player::clone(TextureAtlas & atlas)
{
	return 	std::unique_ptr<Robot>(new Player(*new Animation(atlas.getTexture(), .35, atlas.findRegion("minion")), position_));
}

void Player::fire()
{

}

void Player::update()
{
	if (isIdle) {
		animation_.setTextureRect(0);
	}
	else animation_.update();

	sprite.setPosition(position_);
}
