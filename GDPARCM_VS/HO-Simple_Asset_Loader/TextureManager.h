#include <SFML/Graphics.hpp>;
#include <unordered_map>

class TextureManager
{
    public:
        static TextureManager* getInstance();
        void testFunction();

        void loadAll();
        sf::Texture* getTexture(std::string);
        int iconNum = 0;

    private:
        // set constructor to private
        TextureManager() {}; 
        // set copy contructor to private
        TextureManager(TextureManager const&) {};
        // assignment operator is private
        TextureManager& operator=(TextureManager const&){}; 
        static TextureManager* sharedInstance;

        void loadTexture(std::string,std::string);
        void loadStreamAsset();

        std::unordered_map<std::string, sf::Texture*> textureMap;
        const std::string STREAMING_PATH = "Media/Streaming/";
};