#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class AGameObject
{
public:
	AGameObject(std::string  name);
	virtual ~AGameObject();
	virtual void initialize() = 0;
	virtual void processInput(sf::Event evnet) = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void draw(sf::RenderWindow* targetWindow);
	std::string getName();
protected:
	std::string name;
	sf::Sprite* sprite;
	sf::Texture* texture;
};

