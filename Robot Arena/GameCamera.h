#pragma once
#include <SFML\Graphics\View.hpp>
#include "Robot.h"
#include "Utility.h"


class GameCamera :public sf::View
{
public:
	GameCamera();
	~GameCamera();

	void bounds(Vector2f position,int width, int height,int screenWidth, int screenHeight);
};

