#pragma once
#include "Robot.h"
class Minion :
	public Robot
{
public:
	Minion(Animation &animation, Vector2f position);
	~Minion();
		
	virtual std::unique_ptr<Robot> clone(TextureAtlas &atlas);
};

