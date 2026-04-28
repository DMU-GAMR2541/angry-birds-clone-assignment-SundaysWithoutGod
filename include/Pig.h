#pragma once
#include "DynamicObject.h"
class Pig : public DynamicObject
{
private:

	int i_Health;
	bool b_Destroyed;
	

public:

	Pig() = default;

	//Linking the dynamic class and pig to be able to use the constructor-passing from pig to dynamic it works up
	Pig(std::string pigLocation, sf::Vector2f pigPos, sf::Vector2f pigScale) : DynamicObject(pigLocation, pigPos, pigScale) {};

	//~Pig() = default;
	~Pig() {

		std::cout << "Pig DEATH" << std::endl;
	};
	
	
};

