#pragma once
#include <memory>
#include "State.h"
#include "TextureAtlas.h"
#include "Cursor.h"

class Game;

class GameState : virtual public State
{
public:

	GameState(Game & game);
	~GameState();

	void handleEvent(Event & event) override;
	void update() override;
	void draw(RenderWindow & window) override;

protected:
	std::unique_ptr<TextureAtlas> atlas;
	Vector2f mousePos;
	Game & game_;
	Cursor cursor;
};

