#include "DynamicObject.h"

DynamicObject::DynamicObject(std::string location, b2Vec2 PosIn)
{ 

	if (!texture.loadFromFile(location)) {
		std::cout << "Texture NOT loadiing" << std::endl;

	}
	else
	{
		sprite.setTexture(texture);
	}

	Pos = PosIn;

}



void DynamicObject::setSprite(std::string location)
{
	if (!texture.loadFromFile(location)) {
		std::cout << "Texture NOT loadiing" << std::endl;

	}
	else
	{
		sprite.setTexture(texture);
	}

}
