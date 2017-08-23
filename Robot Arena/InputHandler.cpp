#include "InputHandler.h"

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}
bool InputHandler::hanldeInput(Robot & player)
{
	bool move = false;

	if (keyboard.isKeyPressed(sf::Keyboard::W)) { player.position_.y -= 2 * player.getSpeed();  move = true; }
	if (keyboard.isKeyPressed(sf::Keyboard::S)) { player.position_.y += 2 * player.getSpeed();  move = true; }
	if (keyboard.isKeyPressed(sf::Keyboard::A)) { player.position_.x -= 2 * player.getSpeed();  move = true; }
	if (keyboard.isKeyPressed(sf::Keyboard::D)) { player.position_.x += 2 * player.getSpeed();  move = true; }

	if (move) return true;

	return false;
}
