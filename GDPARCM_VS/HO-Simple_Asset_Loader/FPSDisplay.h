#pragma once
#include "AGameObject.h"
class FPSDisplay : public AGameObject
{
public:
	FPSDisplay();
	~FPSDisplay();
	void initialize() override;
	void processInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;
	void draw(sf::RenderWindow* targetWindow)override;

private:
	sf::Time updateTime;
	sf::Text* statsText;
	int framesPassed = 0;

	sf::Time accumTime;
	int numOfFrames=0;

	void updateFPS(sf::Time deltaTime);
};

