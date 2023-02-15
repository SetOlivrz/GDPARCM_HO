#include "Game.h"
#include "TextureManager.h""
#include <SFML/Graphics.hpp>
#include "GameObjectManager.h"
#include "IconManager.h"
#include "BGObject.h"

Game::Game() : mWindow(sf::VideoMode(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT), "SFML Application") 
{
    mWindow.setFramerateLimit(60);
    deltaTime = sf::Time::Zero;
    // load all textures
    TextureManager::getInstance()->loadAll();

    // create bg object
    BGObject* bgObject = new BGObject("BGObject");
    GameObjectManager::getInstance()->addObject(bgObject);

    // create sprites
    fpsDisplay = new FPSDisplay();
    fpsDisplay->initialize();
    GameObjectManager::getInstance()->addObject(fpsDisplay);
};

void Game::createEntity(std::string key, float x, float y) 
{
    Entity* entity = new Entity();
    entity->getSprite()->setPosition(x, y);
    entity->rootTexName = key;
    entity->frames = 8;
    entityList.push_back(entity);
}

void Game::run() {


    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen()) 
    {

        processEvents();
        deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;
        //int nframes = 0;
        while (timeSinceLastUpdate > TimePerFrame) 
        {
            //nframes++;
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        fpsDisplay->update(deltaTime);

        render();
    }
}

void Game::processEvents() 
{
    sf::Event event;

    while (mWindow.pollEvent(event)) 
    {
        switch (event.type) 
        {
            case sf::Event::Closed:
                mWindow.close();
                break;

            default:
                GameObjectManager::getInstance()->processInput(event);
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) 
{
    IconManager::getInstance()->update(deltaTime);
    GameObjectManager::getInstance()->update(deltaTime);
}

void Game::render() 
{
  mWindow.clear();
  GameObjectManager::getInstance()->draw(&mWindow);
  fpsDisplay->draw(&mWindow);
  mWindow.display();
}

