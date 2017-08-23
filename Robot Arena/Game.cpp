#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::initialize()
{
	window.reset(new RenderWindow(VideoMode(900,720), "Robot Arena"));
	window->setMouseCursorVisible(false);
	window->setFramerateLimit(60);

	width_ = window->getSize().x;
	height_ = window->getSize().y;

	stateManager.reset(new StateManager());
	stateManager->push(new SplashState(*this));
}

void Game::run()
{

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
			if (event.type == Event::Resized)
			{
				width_ = window->getSize().x;
				height_ = window->getSize().y;
			}
		}

		float frameRate = 1.0f / clock.restart().asSeconds();
		string fps = "FPS: " + to_string(frameRate);

		window->clear();

		stateManager->handleEvent(event);
		stateManager->update();
		stateManager->draw(*window);

		window->display();
	}

}
