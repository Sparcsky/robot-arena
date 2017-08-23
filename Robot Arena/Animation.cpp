#include "Animation.h"
Animation::Animation(Texture & texture, float speed, std::vector<IntRect> frames)
	:frames_(frames), speed_(speed), sprite_(sprite_), texture_(texture)
{
}

Animation::~Animation()
{
	delete sprite_;
}

void Animation::setSprite(Sprite &sprite)
{
	sprite_ = &sprite;
	sprite_->setOrigin(frames_[0].width / 2, frames_[0].height / 2);
	sprite_->setTexture(texture_);
}

bool Animation::isAnimationFinished()
{
	return frameEnded_;
}

void Animation::setTextureRect(int ID)
{
	sprite_->setTextureRect(frames_[ID]);
	sprite_->setOrigin(frames_[ID].width / 2, frames_[ID].height / 2);
}

void Animation::setPlayMode(PlayMode playMode)
{
	this->playMode = playMode;
}
void Animation::update()
{
	int size = frames_.size();
	frameSpeed_ +=  speed_ + clock.restart().asSeconds();

	if (frameSpeed_ >= size) {
		frameSpeed_ = 0;
		frameEnded_ = true;
	}
	sprite_->setTextureRect(frames_[frameSpeed_]);
}
