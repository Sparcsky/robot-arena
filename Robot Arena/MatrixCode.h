#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class MatrixCode
{
public:
	MatrixCode(sf::Font & font, float speed, int size, int width, int height);
	~MatrixCode();

	void setSpeed(float speed);
	void stopMatrix(bool time);
	void activate(sf::RenderWindow &window);
	sf::Text createCode(float x,float y,char a,bool blur,Color color);

private:
	std::vector<Text> texts;
	sf::Font font_;
	std::string binary = "10";

	int width_ = 0 , height_ = 0;
	float x = 0, y = 0, speed_ = 0;

	bool isStop = false;
	void generatePosition();
	void generateString();
};

