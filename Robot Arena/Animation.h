#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

using namespace sf;

enum class PlayMode { Loop, Normal };

class Animation
{
public:
	Animation(Texture & texture, float speed, std::vector<IntRect> frames);
	~Animation();
	void setSprite(Sprite &sprite);
	void setTextureRect(int ID);
	void setPlayMode(PlayMode playmode);
	void update();
	bool isAnimationFinished();

private:
	std::vector<IntRect> frames_;
	Sprite *sprite_;
	Texture &texture_;

	PlayMode playMode;
	Clock clock;

	float speed_, frameSpeed_ = 0;
	bool frameEnded_;

};

