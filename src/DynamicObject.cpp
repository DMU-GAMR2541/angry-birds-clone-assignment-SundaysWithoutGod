#include "DynamicObject.h"

DynamicObject::DynamicObject(std::string location)
{ 

	if (!texture.loadFromFile(location)) {
		std::cout << "Texture NOT loadiing" << std::endl;

	}
	else
	{
		sprite.setTexture(texture);
	}

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
