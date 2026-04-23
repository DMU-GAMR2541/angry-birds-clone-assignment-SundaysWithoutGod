#pragma once
#include "GameObject.h"
class DynamicObject : public GameObject
{
private:
	
	//Position--ALL
	b2Vec2 Pos;
	sf::Sprite sprite;
	sf::Texture texture;
	//Create sprite
	//Load texture
	//Load File--use if/else for checking
	
public:
	DynamicObject() = default;
	//~DynamicObject() = default;

	~DynamicObject() {

		std::cout << "DEATH" << std::endl;
	};
	//Pos getter and setters

	//passing a in a string that will be the location in the file  of this sprite instance
	DynamicObject(std::string location, b2Vec2 PosIn);

	void  setSprite(std::string location);

	sf::Sprite getSprite() {

		return sprite;

	}
};

