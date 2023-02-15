#pragma once
#include "AGameObject.h"

class AirplanePlayer :public AGameObject
{
public:
	AirplanePlayer(std::string name);
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

private:
	const float playerSpeed = 300.f;
	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;


};
