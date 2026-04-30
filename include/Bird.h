#pragma once
#include "DynamicObject.h"
class Bird : public DynamicObject
{
private:
	bool b_Destroyed;
	/*int i_Speed;
	float i_Weight;*/
	int i_DamageGiven;


public:
	Bird() = default;
	//~Bird() = default;

	Bird(b2World& world, std::string birdLocation, sf::Vector2f birdPos, sf::Vector2f birdScale, float birdDen, float birdFric, float birdRest) : DynamicObject(world, birdLocation, birdPos, birdScale, birdDen, birdFric, birdRest) {};

	~Bird() {

		std::cout << "The bird has flown the coop" << std::endl;
	};
};

