#pragma once
#include <SFML/System.hpp>
#include "AGameObject.h"

class IconManager
{
public:
	static IconManager* getInstance();
	void Initialize();
	void update(sf::Time deltaTime);
	void spawnIconObject();
private:
	// set constructor to private
	IconManager() {};
	// set copy contructor to private
	IconManager(IconManager const&) {};
	// assignment operator is private
	IconManager& operator=(IconManager const&) {};
	static IconManager* sharedInstance;

	bool spawnIcon = true;
	int iconWidth = 68;
	int iconHeight = 68;
	float delay = 0.10f;
	float ticks = 0.0f;
	int row = 0;
	int col = 0;
	int maxRow = 28;
	int maxCol = 28;

	int	currIconIndex = 0;

};

