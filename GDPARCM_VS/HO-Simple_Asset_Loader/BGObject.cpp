#include "BGObject.h"
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Game.h"

BGObject::BGObject(std::string name) : AGameObject(name) {}

void BGObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("desert_bg"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	//make BG height x k to emulate repeating BG.
	sprite->setTextureRect(sf::IntRect(0, 0, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT * 8));
	sprite->setPosition(0, -Game::WINDOW_HEIGHT * 7);
}

void BGObject::processInput(sf::Event event)
{
}

void BGObject::update(sf::Time deltaTime)
{
	//make BG scroll slowly
	sf::Vector2f offset(0.0f, 0.0f);
	offset.y += SPEED_MULTIPLIER;
	sprite->move(offset * deltaTime.asSeconds());

	sf::Vector2f localPos = sprite->getPosition();
	if (localPos.y * deltaTime.asSeconds() > 0) {
		//reset position
		sprite->setPosition(0, -Game::WINDOW_HEIGHT * 7);
	}
}

