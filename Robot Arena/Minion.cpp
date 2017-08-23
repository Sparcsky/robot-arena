#include "Minion.h"
#include <memory>

Minion::Minion(Animation & animation, Vector2f position)
	:Robot(animation,position)
{

}

Minion::~Minion()
{
}
std::unique_ptr<Robot> Minion::clone(TextureAtlas & atlas)
{
	std::unique_ptr<Robot> minion(new Minion(*new Animation(atlas.getTexture(), .35, atlas.findRegion("minion")), position_));
	return minion;
}
