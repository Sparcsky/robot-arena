#include "RobotGenerator.h"
#include <vector>

RobotGenerator::RobotGenerator()
{

}

RobotGenerator::~RobotGenerator()
{
}

Robot *RobotGenerator::generate(RobotType type, TextureAtlas &atlas, std::string region, Vector2f position)
{
	Robot *robot = nullptr;

	Texture &texture = atlas.getTexture();
	std::vector<sf::IntRect> &frames = atlas.findRegion(region);

	switch (type) {
	case RobotType::MINION:
	{
		robot = new Minion(*new Animation(texture, 2.9, frames), position);
		break;
	}
	case RobotType::PLAYER:
	{
		robot = new Player(*new Animation(texture, 1.4f, frames), position);
		break;

	}
	case RobotType::SNIPER:
		break;
	default:
		return nullptr;
	}

	return robot;
}
