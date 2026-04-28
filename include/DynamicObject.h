#pragma once
#include "GameObject.h"
class DynamicObject : public GameObject
{
private:
	
	//Position--ALL
	
	sf::Sprite spriteRender;
	sf::Texture spriteTexture;
	sf::Vector2f spriteScale;
	const float SCALE = 30.0f;
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
	DynamicObject(std::string location, sf::Vector2f PosIn, sf::Vector2f scale);
	
	void  setSprite(std::string location);

	sf::Sprite getSprite() {

		return spriteRender;

	}


};

