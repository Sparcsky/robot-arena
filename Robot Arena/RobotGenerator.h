#pragma once
#include <SFML\Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include "Robot.h"
#include "Player.h"
#include "RobotType.h"
#include "Minion.h"
#include "TextureAtlas.h"

class RobotGenerator
{
public:
	RobotGenerator();
	~RobotGenerator();

	static Robot* generate(RobotType type, TextureAtlas &atlas, std::string region, Vector2f position);

private:
};

