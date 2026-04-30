#pragma once
#include "DynamicObject.h"
class Pig : public DynamicObject
{
private:

	int i_Health = 0;
	bool b_Destroyed = 0;
	

public:

	Pig() = default;

	//Linking the dynamic class and pig to be able to use the constructor-passing from pig to dynamic it works up
	Pig(std::string pigLocation, sf::Vector2f pigPos, sf::Vector2f pigScale) : DynamicObject(pigLocation, pigPos, pigScale) {};
	
	//Second constroctor that adds the box2ed world onto the object 
	Pig(b2World& world, std::string pigLocation, sf::Vector2f pigPos, sf::Vector2f pigScale, float pigDen, float pigFric, float pigRest) : DynamicObject(world ,pigLocation, pigPos, pigScale, pigDen, pigFric, pigRest) {};

	//~Pig() = default;
	~Pig() {
		std::cout << "Pig DEATH" << std::endl;
	};
	void setHealth(int pigHealth);
	int getHealth();
	
};

