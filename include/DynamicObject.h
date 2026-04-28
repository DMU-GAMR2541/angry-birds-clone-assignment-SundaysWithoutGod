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

	//Box2D Dynamic 
	b2Vec2 b2d_Pos;//Position-
	b2BodyDef b2d_bodyDef;//Have a object body find our what's its doing or define what it is
	b2FixtureDef b2d_fixtureDef;//Values that are attached to the object body like density
	b2Body* b2d_Body;//The actuall body object
	b2CircleShape b2d_dynamicShape;//the shell around the image that would be the 'collider'

	
	
public:
	
	
	DynamicObject() = default;
	//~DynamicObject() = default;

	~DynamicObject() {

		std::cout << "DEATH" << std::endl;
	};
	//Pos getter and setters

	//passing a in a string that will be the location in the file  of this sprite instance
	DynamicObject(std::string location, sf::Vector2f PosIn, sf::Vector2f scale);

	//Box2d constructor
	DynamicObject(b2World ObjectsWorld, std::string location, sf::Vector2f PosIn, sf::Vector2f scale);

	void  setSprite(std::string location);


	sf::Sprite getSprite() {

		return spriteRender;

	}


};

