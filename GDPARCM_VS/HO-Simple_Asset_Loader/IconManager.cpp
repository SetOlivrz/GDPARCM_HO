#include "IconManager.h"
#include <iostream>
#include "IconObject.h"
#include "TextureManager.h"
#include "GameObjectManager.h"

IconManager* IconManager::sharedInstance = NULL;

IconManager* IconManager::getInstance() 
{
	if (sharedInstance == NULL) 
	{
		sharedInstance = new IconManager();
	}
	return sharedInstance;
}


void IconManager::Initialize()
{
	currIconIndex = 0;
}

void IconManager::update(sf::Time deltaTime)
{
	if (spawnIcon)
	{
		if (ticks < delay)
		{
			ticks += deltaTime.asSeconds();
		}
		else
		{
			ticks = 0.0f;
			if (currIconIndex < TextureManager::getInstance()->iconNum)
			{
				spawnIconObject();
			}
			else
			{
				spawnIcon = false;
			}
		}
	}
}

void IconManager::spawnIconObject()
{
	//set position
	int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
	float x = this->col * IMG_WIDTH;
	float y = this->row * IMG_HEIGHT;
	currIconIndex++;
	IconObject* icon = new IconObject("Icon",std::to_string(currIconIndex) + "_Icon", x, y);


	this->col++;
	if (this->col == this->maxCol)
	{
		this->col = 0;
		this->row++;

		if (row >= maxRow)
		{
			spawnIcon = false;
		}
	}
	GameObjectManager::getInstance()->addObject(icon);
}
