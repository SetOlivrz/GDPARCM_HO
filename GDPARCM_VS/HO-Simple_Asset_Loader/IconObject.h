#pragma once
#include "AGameObject.h"
class IconObject : public AGameObject
{
public:
	IconObject(std::string name, std::string texture, float posX, float posY);
	void initialize()override;
	void update(sf::Time deltaTime);
	virtual void processInput(sf::Event evnet) override;
private:
	float width;
	float height;

	// Inherited via AGameObject

};

