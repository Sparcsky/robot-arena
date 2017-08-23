#include "Spawner.h"

Spawner::Spawner(Robot * prototype)
	:prototype_(prototype)
{
}

Spawner::Spawner()
{
}

Spawner::~Spawner()
{
}

std::unique_ptr<Robot> Spawner::spawnRobot(TextureAtlas & atlas)
{
	return prototype_->clone(atlas);
}
