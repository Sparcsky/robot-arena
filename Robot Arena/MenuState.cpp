#include "MenuState.h"

MenuState::MenuState(Game & game) :GameState(game)
{

	atlas.reset(new TextureAtlas("assets/sprites/menu.png", "assets/data/menu_data.txt"));
	splash = new Splash(atlas->getTexture(), atlas->getImage("menu_bg"), true, true, game_.width_, game_.height_);

	loadAssets();

	string names[] = { "start","option","credit","exit" };

	for (int i = 0; i < 4; i++) 
	{
		Buttons *button = new Buttons(atlas->getTexture(), atlas->getImage(names[i]));
		buttons.push_back(button);
		buttons[i]->setPosition(game.width_ / 2, game.height_ / 4 + i * buttons[i]->getHeight() * 1.5);
	}

	srand(time(NULL));

	for (int i = 0; i < 60; i++)
	{
		float speed = (rand() % 4 + 0.5);
		MatrixCode *code = new MatrixCode(*font, speed, rand() % 10 + 5, game_.width_, game_.height_);
		matrices.push_back(code);
	}

}

MenuState::~MenuState()
{
	delete font;
	delete splash;

	for (int i = 0; i < matrices.size();i++)
		delete matrices[i];

	for (int i = 0; i < buttons.size(); i++)
		delete buttons[i];
}

void MenuState::loadAssets()
{
	font = new Font();

	if (!sbClick.loadFromFile("assets/sounds/click.wav")) EXIT_FAILURE;
	if (!music.openFromFile("assets/sounds/music.wav")) EXIT_FAILURE;
	if (!sbHover.loadFromFile("assets/sounds/hover.flac")) EXIT_FAILURE;
	if (!font->loadFromFile("assets/fonts/matrix_code.ttf")) EXIT_FAILURE;

	click.setBuffer(sbClick);
	hover.setBuffer(sbHover);
	hover.setLoop(false);
	music.setLoop(true);
	music.play();
}

void MenuState::handleEvent(Event & event)
{
}

void MenuState::update()
{
	GameState::update();

	for (int i = 0;i < buttons.size(); i++)
	{
		if (buttons[i]->isClicked(mousePos))
		{
			if (hover.getStatus() == hover.Stopped) hover.play();

			switch (i)
			{
			case 0:
				music.stop();
				game_.stateManager->pop();
				game_.stateManager->push(new PlayState(game_));
			}
		}
		buttons[i]->actAnimation();
	}

	splash->act();
}

void MenuState::draw(RenderWindow & window)
{
	splash->draw(window);

	for (int i = 0; i < buttons.size(); i++) 
	{
		buttons[i]->draw(window);
	}

	cursor.draw(window);

	//float speed = rand() % (2) - ((0.1 + 1)) + 0.1;
	//int i = rand() % matrices.size();
	//matrices[i]->setSpeed(speed);
	//matrices[i]->stopMatrix(true);

	for (int i = 0; i < matrices.size(); i++) 
	{
		matrices[i]->activate(window);
	}

}
