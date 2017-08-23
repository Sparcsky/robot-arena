#include "TextureAtlas.h"

TextureAtlas::TextureAtlas(std::string texturePath, std::string filePath)
{
	texture.reset(new sf::Texture());
	if (!texture->loadFromFile(texturePath)) EXIT_FAILURE;

	readData(filePath);
}

TextureAtlas::TextureAtlas()
{
}

TextureAtlas::~TextureAtlas()
{

}

void TextureAtlas::readData(std::string filePath)
{
	std::ifstream file;

	file.open(filePath);

	if (file.is_open())
	{
		std::string line = "";
		std::string spriteName = "";
		const std::string tagName = "name: ";

		while (std::getline(file, line))
		{
			std::size_t found = line.find(tagName);

			if (found != std::string::npos)
			{
				std::vector<int> data;
				std::string tag, num1, num2;
				spriteName = line.erase(0, tagName.size());

				for (int i = 0;i < 2; i++)
				{
					file >> tag >> num1 >> num2;
					data.push_back(std::stoi(num1));
					data.push_back(std::stoi(num2));

				}
				for (int i = 0; i < 2; i++)
				{
					file >> tag >> num1;
					data.push_back(std::stoi(num1));
				}

				std::vector<sf::IntRect> frames = pushFrames(data);
				map.insert({ spriteName,frames });
			}
		}
		file.close();
	}

}

std::vector<sf::IntRect> TextureAtlas::pushFrames(std::vector<int> data)
{
	float x = 0, y = 0;
	int width = 0, height = 0, lengthX = 0, lengthY = 0;

	x = data[0];
	y = data[1];
	width = data[2];
	height = data[3];
	lengthX = data[4];
	lengthY = data[5];

	width /= lengthX;
	height /= lengthY;

	std::vector<sf::IntRect> frames;
	for (int i = 0; i < lengthY; i++)
	{
		for (int j = 0; j < lengthX; j++)
		{
			frames.push_back(sf::IntRect(x + j * width, y + i * height, width, height));
		}
	}
	return frames;
}

sf::Texture & TextureAtlas::getTexture()
{
	return *texture;
}


sf::IntRect TextureAtlas::getImage(std::string key)
{
	return map[key].front();
}
 
std::vector<sf::IntRect> TextureAtlas::findRegion(std::string key)
{
	auto search = map.find(key);
	std::vector<sf::IntRect> frames;
	
	if (search != map.end())
		frames = map[key];
	else
		std::cout << "TEXTURE REGION NOT FOUND";

	return frames;
}
