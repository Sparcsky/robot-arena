#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "GameState.h"
#include "StateManager.h"
#include "SplashState.h"
#include "PlayState.h"

using namespace std;
using namespace sf;

class Game {
public:
	std::unique_ptr<RenderWindow> window;
	std::unique_ptr<StateManager> stateManager;

	
	float width_;
	float height_;

	Game();
	~Game();

	void initialize();
	void run();

private:
	Clock clock;
	string title = "Robot Arena";
};