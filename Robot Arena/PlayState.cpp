#include "PlayState.h"
PlayState::PlayState(Game & game) :GameState(game)
{
	atlas.reset(new TextureAtlas("assets/sprites/robots.png", "assets/data/robot_data.txt"));
	mapAtlas.reset(new TextureAtlas("assets/sprites/objects.png", "assets/data/objects_data.txt"));
	background.setTexture(mapAtlas->getTexture());
	background.setTextureRect(mapAtlas->getImage("stage_1"));
	
	player = RobotGenerator::generate(RobotType::PLAYER, *atlas, "heavy_gunner_walk", Vector2f(rand() % 1000, rand() % 1000));

	camera.setCenter(player->position_);
}

PlayState::~PlayState()
{
	delete player;
}
void PlayState::handleEvent(Event & event)
{
	if (input.hanldeInput(*player)) {
		player->isIdle = false;
	}
	else player->isIdle = true;
}


void PlayState::update()
{
	GameState::update();

	player->setBoundary(background.getGlobalBounds().width, background.getGlobalBounds().height, camera.getSize().x, camera.getSize().y);
	player->faceDirectTo(mousePos);
	player->update();

	camera.bounds(player->getPosition(), background.getGlobalBounds().width, background.getGlobalBounds().height, camera.getSize().x, camera.getSize().y);
}

void PlayState::draw(RenderWindow & window)
{

	window.setView(camera);
	window.draw(background);
	
	
	player->draw(window);
	
	cursor.draw(window);
}
