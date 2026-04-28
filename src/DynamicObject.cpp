#include "DynamicObject.h"

DynamicObject::DynamicObject(std::string location, sf::Vector2f PosIn, sf::Vector2f scale)
{ 

	if (!spriteTexture.loadFromFile(location)) {
		std::cout << "Texture NOT loadiing" << std::endl;

	}
	else
	{
		spriteRender.setTexture(spriteTexture);
		//setting the origins-taking it from the corner to the center point
		spriteRender.setOrigin(spriteRender.getLocalBounds().getSize().x/2.0f, spriteRender.getLocalBounds().getSize().y/2.0f);
	}
	
	spriteRender.setScale(scale);
	spriteRender.setPosition(sf::Vector2f(PosIn.x, PosIn.y));
}



DynamicObject::DynamicObject(b2World ObjectsWorld, std::string location, sf::Vector2f PosIn, sf::Vector2f scale)
{
	if (!spriteTexture.loadFromFile(location)) {
		std::cout << "Texture NOT loadiing" << std::endl;

	}
	else
	{
		spriteRender.setTexture(spriteTexture);
		//setting the origins-taking it from the corner to the center point
		spriteRender.setOrigin(spriteRender.getLocalBounds().getSize().x / 2.0f, spriteRender.getLocalBounds().getSize().y / 2.0f);
	}

	spriteRender.setScale(scale);
	spriteRender.setPosition(sf::Vector2f(PosIn.x, PosIn.y));



	//Box2D
	b2d_bodyDef.type = b2_dynamicBody;
	b2d_bodyDef.position = b2d_Pos;
	//Creates the bodies in the world
	b2d_Body = ObjectsWorld.CreateBody(&b2d_bodyDef);


}

void DynamicObject::setSprite(std::string location)
{
	if (!spriteTexture.loadFromFile(location)) {
		std::cout << "Texture NOT loadiing" << std::endl;

	}
	else
	{
		spriteRender.setTexture(spriteTexture);
	}

}
