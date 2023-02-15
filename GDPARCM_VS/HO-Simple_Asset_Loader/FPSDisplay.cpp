#include "FPSDisplay.h"
#include <iostream>
#include "GameObjectManager.h"
#include "Game.h"

FPSDisplay::FPSDisplay() : AGameObject("FPSCounter")
{
}

FPSDisplay::~FPSDisplay()
{
	delete this->statsText->getFont();
	delete this->statsText;
	AGameObject::~AGameObject();
}

void FPSDisplay::initialize()
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("Media/Sansation.ttf");

	this->statsText = new sf::Text();
	this->statsText->setFont(*font);
	this->statsText->setPosition(10, Game::WINDOW_HEIGHT-150);
	this->statsText->setOutlineColor(sf::Color(1.0f, 1.0f, 1.0f));
	this->statsText->setOutlineThickness(2.5f);
	this->statsText->setCharacterSize(35);

}

void FPSDisplay::processInput(sf::Event event)
{
}

void FPSDisplay::update(sf::Time deltaTime)
{
	this->updateFPS(deltaTime);
}

void FPSDisplay::draw(sf::RenderWindow* targetWindow)
{
	targetWindow->draw(*statsText);

}

void FPSDisplay::updateFPS(sf::Time deltaTime)
{
	accumTime += deltaTime;
	numOfFrames += 1;
	if (accumTime >= sf::seconds(1.0f)) 
	{ // per second
		//this->statsText->setString("FPS:" + std::to_string(numOfFrames) + "\n");

		statsText->setString("FPS: " + std::to_string(numOfFrames));
		accumTime -= sf::seconds(1.0f);
		numOfFrames = 0;


	}
}
