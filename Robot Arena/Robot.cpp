#include "Robot.h"
#include "Utility.h"
Robot::Robot(Animation &animation, Vector2f position)
	:animation_(animation), position_(position)
{
	animation_.setSprite(sprite);
}
Robot::~Robot()
{
	delete &animation_;
}

void Robot::fire()
{

}

void Robot::faceDirectTo(Vector2f target)
{
	float dx = target.x - position_.x;
	float dy = target.y - position_.y;

	angle_ = atan2f(dy, dx);

	sprite.setRotation(Math::radianToPi(angle_) + 90);
}

void Robot::setBoundary(int width, int height, int screenWidth, int screenHeight)
{
	position_.x = Math::clamp(position_.x, 0 + getWidth() / 2,  width - getWidth() / 2);
	position_.y = Math::clamp(position_.y, 0 + getHeight() / 2, height - getHeight() / 2);
}

void Robot::update()
{
	animation_.update();
}

Animation & Robot::getAnimation()
{
	return animation_;
}

float Robot::getSpeed()
{
	return speed_;
}

