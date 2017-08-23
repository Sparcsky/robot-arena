#pragma once
#include <SFML\Window\Keyboard.hpp>
#include "GameState.h"
#include "RobotGenerator.h"
#include "Game.h"
#include "TextureAtlas.h"
#include "InputHandler.h"
#include "GameCamera.h"
#include "Spawner.h"

class PlayState : public GameState
{
public:
	PlayState(Game & game);
	~PlayState();

	void handleEvent(Event & event) override;
	void update() override;
	void draw(RenderWindow & window) override;
private:

	Robot *player;
	Sprite background;
	InputHandler input;
	GameCamera camera;
	std::unique_ptr<TextureAtlas> mapAtlas;
};

