#include "IconObject.h"
#include "TextureManager.h"
#include "Game.h"

IconObject::IconObject(std::string name, std::string texture, float posX, float posY):AGameObject(name)
{
    //assign texture
    sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture(texture));
    sprite->setPosition(posX, posY);
}

void IconObject::initialize()
{
  
}

void IconObject::update(sf::Time deltaTime)
{
}

void IconObject::processInput(sf::Event evnet)
{
}
