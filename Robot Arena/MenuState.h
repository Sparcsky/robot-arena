#pragma once
#include <cstdlib>
#include <ctime>

#include "GameState.h"
#include "PlayState.h"
#include "Buttons.h"
#include "ButtonEffect.h"
#include "MatrixCode.h"
#include "Splash.h"
#include "Game.h"

class MenuState : public GameState
{
public:
	MenuState(Game & game);
	~MenuState();

	void loadAssets();
	void handleEvent(Event & event) override;
	void update() override;
	void draw(RenderWindow & window) override;

private:
	Font *font;
	Splash * splash;

	vector<Buttons*> buttons;
	vector<MatrixCode*> matrices;
	
	SoundBuffer sbHover, sbClick;
	Sound hover, click;
	Music music;
};

