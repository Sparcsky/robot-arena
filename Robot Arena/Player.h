#pragma once
#include "Robot.h"

class Player :public Robot
{
public:
	Player(Animation &animation, Vector2f position);
	~Player();
	
	virtual std::unique_ptr<Robot> Player::clone(TextureAtlas & atlas);

	void fire() override;
	void update() override;
};


