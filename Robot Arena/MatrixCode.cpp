#include "MatrixCode.h"
#include <SFML\OpenGL.hpp>

MatrixCode::MatrixCode(sf::Font & font, float speed, int size, int width, int height) :
	font_(font), speed_(speed), width_(width), height_(height)
{
	x = rand() % width;
	y = (rand() % height) - height;

	Color color = sf::Color(1, 253, 200, 200);

	for (int i = 0; i < size; i++) 
	{
		color.a = i * 50;
		Text text = createCode(x, y, '0', rand() % 2, color);
		texts.push_back(text);
	}
}

MatrixCode::~MatrixCode()
{
}

sf::Text MatrixCode::createCode(float x, float y, char a, bool blur, sf::Color color)
{
	sf::Text newText;
	newText.setFont(font_);
	newText.setCharacterSize(17);
	newText.setString(a);
	newText.setFillColor(color);
	newText.setPosition(x, y);
	if (blur)
	{
		newText.setOutlineThickness(1);
		newText.setOutlineColor(color);
	}
	return newText;
}

void MatrixCode::generatePosition()
{
	y = ((rand() % height_) - height_ * 2);
	x = rand() % width_;
}

void MatrixCode::generateString()
{
	texts[rand() % (int) texts.size()].setString(binary[rand() % 2]);
}

void MatrixCode::setSpeed(float speed)
{
	speed_ = speed;
}

void MatrixCode::stopMatrix(bool stop)
{
	isStop = stop;
}

void MatrixCode::activate(sf::RenderWindow &window)
{
	if(!isStop)	y += sin(y) + 2* speed_;
	if (y > height_) {
		generatePosition();
	}
	generateString();

	for (int i = 0; i < texts.size(); i++) {
		texts[i].setPosition(x, y + i * 17);
		window.draw(texts[i]);
	}
}