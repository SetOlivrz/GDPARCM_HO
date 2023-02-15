#include <stddef.h>
#include <iostream>
#include <filesystem>
#include <fstream>


#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance() 
{
	//initialize only when we need it
	if (sharedInstance == NULL) 
	{
		sharedInstance = new TextureManager();
	}
	return sharedInstance;
}

void TextureManager::loadAll() 
{
	sf::Texture* iconTex = new sf::Texture;

	for (const auto& entry : std::filesystem::directory_iterator(STREAMING_PATH)) 
	{
		if (!iconTex->loadFromFile(entry.path().string()))
		{
			std::cerr << "Failed to load texture " << entry.path().string() << std::endl;
			continue;
		}
		std::cout << "loaded texture " << entry.path().string() << std::endl;
		iconNum++;
		loadTexture(std::to_string(iconNum) + "_Icon", entry.path().string());
	}

	loadTexture("desert_bg", "Media/Textures/Desert.png");
	sf::Texture* bgTex;
	bgTex = getTexture("desert_bg");
	bgTex->setRepeated(true);
}

void TextureManager::loadTexture(std::string key, std::string path) 
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

void TextureManager::loadStreamAsset()
{
	
}

sf::Texture* TextureManager::getTexture(std::string key) 
{
	if (textureMap[key] != NULL) 
	{
		return textureMap[key];
	}
	else 
	{
		std::cout << "No texture found for " << key;
		return NULL;
	}
}

void TextureManager::testFunction() {
	std::cout << "Hi, I'm single-ton ;D";
}