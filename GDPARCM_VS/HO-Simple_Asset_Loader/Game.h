#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "FPSDisplay.h"
#include <vector>

class Game {
    public:
        static const int WINDOW_WIDTH = 1920;
        static const int WINDOW_HEIGHT = 1080;
        const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
        sf::Time deltaTime;


        Game();
        void run();
    private:
        void processEvents();
        void update(sf::Time);
        void render();
        void createEntity(std::string, float, float);
    private:
        sf::RenderWindow mWindow;
        std::vector<Entity*> entityList;
        FPSDisplay* fpsDisplay;
        sf::Clock clock;

};