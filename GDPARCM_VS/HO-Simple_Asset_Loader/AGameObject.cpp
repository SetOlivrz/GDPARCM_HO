#include "AGameObject.h"

AGameObject::AGameObject(std::string name) 
{
	this->name = name;
}

AGameObject::~AGameObject() 
{
	if (this->sprite != NULL) 
	{
		delete this->sprite;
	}
}

std::string AGameObject::getName() 
{
	return name;
}

void AGameObject::draw(sf::RenderWindow* targetWindow) 
{
	targetWindow->draw(*sprite);
}