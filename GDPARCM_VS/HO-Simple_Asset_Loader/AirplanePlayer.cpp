#include "AirplanePlayer.h"
#include "TextureManager.h"
#include "Game.h"

AirplanePlayer::AirplanePlayer(std::string name) : AGameObject(name) {}

void AirplanePlayer::initialize()
{
    //assign texture
    sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("eagle"));
    sprite->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
}

void AirplanePlayer::processInput(sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::W)
            isMovingUp = true;
        else if (event.key.code == sf::Keyboard::S)
            isMovingDown = true;

        if (event.key.code == sf::Keyboard::A)
            isMovingLeft = true;

        else if (event.key.code == sf::Keyboard::D)
            isMovingRight = true;
        break;

    case sf::Event::KeyReleased:
        if (event.key.code == sf::Keyboard::W)
            isMovingUp = false;
        else if (event.key.code == sf::Keyboard::S)
            isMovingDown = false;

        if (event.key.code == sf::Keyboard::A)
            isMovingLeft = false;

        else if (event.key.code == sf::Keyboard::D)
            isMovingRight = false;
        break;
    }

}

void AirplanePlayer::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (isMovingUp) {
        movement.y -= playerSpeed;
    }
    if (isMovingDown) {
        movement.y += playerSpeed;
    }
    if (isMovingLeft) {
        movement.x -= playerSpeed;
    }
    if (isMovingRight) {
        movement.x += playerSpeed;
    }
    sprite->move(movement * deltaTime.asSeconds());
}