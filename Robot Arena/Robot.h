#pragma once
#include <memory>
#include "Entity.h"
#include "Animation.h"
#include "Weapon.h"
#include "Bullet.h"
#include "TextureAtlas.h"

class Robot : public Entity
{
public:
	Vector2f position_;
	bool isIdle = true;

	Robot(Animation &animation, Vector2f position);
	~Robot();

	void setBoundary(int left, int width, int top, int height);
	virtual void fire();
	virtual void faceDirectTo(Vector2f position);
	virtual void update() override;
	virtual std::unique_ptr<Robot> clone(TextureAtlas &atlas) = 0;

	float getSpeed();
	Animation & getAnimation();

protected:
	Animation & animation_;
	Bullet bullet_;
	Weapon weapon_;

	bool debug_ = false;
	float angle_ = 0;
	float speed_ = 2.5f;
	int health = 0;
};

