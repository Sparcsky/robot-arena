#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <memory>

class TextureAtlas
{
public:
	TextureAtlas(std::string texturePath, std::string filePath);
	TextureAtlas();
	~TextureAtlas();

	std::vector<sf::IntRect> findRegion(std::string key);
	sf::IntRect getImage(std::string key);
	sf::Texture & getTexture();

	void readData(std::string filePath);
	
private:
	std::unique_ptr<sf::Texture> texture;
	std::unordered_map<std::string, std::vector<sf::IntRect>> map;

	std::vector<sf::IntRect> pushFrames(std::vector<int> data);
};

