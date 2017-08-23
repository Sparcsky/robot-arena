#include "GameCamera.h"


GameCamera::GameCamera()
{
}

GameCamera::~GameCamera()
{
}
void GameCamera::bounds(Vector2f position, int width, int height, int screenWidth, int screenHeight)
{
	float camX = Math::clamp(position.x, screenWidth / 2, width - screenWidth / 2);
	float camY = Math::clamp(position.y, screenHeight / 2, height -screenHeight / 2);
	setCenter(Vector2f(camX,camY));
}