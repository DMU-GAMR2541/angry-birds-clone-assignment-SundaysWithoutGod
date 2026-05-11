#pragma once
#include "GameObject.h"
class StaticObject : public GameObject
{
private:
	float sizeX;
	float sizeY;
	
	//the basics of making a rect shape in SFML
	sf::RectangleShape rectShape;
	sf::Color rectColour;
	sf::Vector2f rectOrgin;

public:
	StaticObject() = default;
	~StaticObject() = default;
	StaticObject(sf::RectangleShape rect, sf::Color colour, sf::Vector2f orgin);
	void updateSprite() override;




};

