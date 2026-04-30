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



DynamicObject::DynamicObject(b2World& ObjectsWorld, std::string location, sf::Vector2f PosIn, sf::Vector2f scale, float den, float fric, float rest)
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
	b2d_bodyDef.type = b2_dynamicBody; //Adding the body
	b2d_bodyDef.position = b2Vec2(PosIn.x/SCALE, PosIn.y/SCALE);//Adding position
	
	//Creates the bodies in the world
	b2d_Body = ObjectsWorld.CreateBody(&b2d_bodyDef);

	//Getting the radius of the sprite and then converting to box2d
	b2d_dynamicShape.m_radius = (spriteRender.getLocalBounds().width / 2) / SCALE;

	//Box2D	 Fixtures
	b2d_fixtureDef.shape = &b2d_dynamicShape;
	
	//Default fixtures
	b2d_fixtureDef.density = den;
	b2d_fixtureDef.friction = fric;
	b2d_fixtureDef.restitution = rest;

	b2d_Body->CreateFixture(&b2d_fixtureDef);



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

void DynamicObject::setFixtures(float den, float fric, float rest) {
	
	//den = b2d_fixtureDef.density;
	//fric = b2d_fixtureDef.friction;
	//rest = b2d_fixtureDef.restitution;
	b2d_fixtureDef.density = den;
	b2d_fixtureDef.friction = fric;
	b2d_fixtureDef.restitution = rest;
	b2d_Body->CreateFixture(&b2d_fixtureDef);


};

void DynamicObject::updateSprite()
{
	//Setting the position from SFML to box2D
	spriteRender.setPosition(sf::Vector2(b2d_Body->GetPosition().x * SCALE, b2d_Body->GetPosition().y * SCALE));
	

}
