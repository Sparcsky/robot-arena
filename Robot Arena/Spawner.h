#pragma once
#include "Robot.h"
#include "TextureAtlas.h"
class Spawner
{
public:
	Spawner(Robot * prototype);
	Spawner();
	~Spawner();

	std::unique_ptr<Robot> spawnRobot(TextureAtlas & atlas);
private:
	Robot * prototype_;
};

