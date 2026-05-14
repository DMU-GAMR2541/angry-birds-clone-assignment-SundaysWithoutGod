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
	//Create Textures

	if (!spriteTexture.loadFromFile(location)) {
		std::cout << "Texture NOT loadiing" << std::endl;

	}
	else
	{
		spriteRender.setTexture(spriteTexture);
		//setting the origins-taking it from the corner to the center point

	}
	spriteRender.setOrigin(spriteRender.getLocalBounds().width / 2.0f, spriteRender.getLocalBounds().height / 2.0f);
	spriteRender.setScale(scale);

	spriteRender.setPosition(PosIn);

	//Box2D
	b2d_bodyDef = b2BodyDef();
	b2d_bodyDef.type = b2_dynamicBody; //Adding the body
	b2d_bodyDef.position = b2Vec2(PosIn.x/SCALE, PosIn.y/SCALE);//Adding position

	//Creates the bodies in the world
	b2d_Body = ObjectsWorld.CreateBody(&b2d_bodyDef);

	//Getting the radius of the sprite and then converting to box2d
	b2d_dynamicShape.m_radius = (spriteRender.getLocalBounds().width / 2.0f) / SCALE;

	//Box2D	 Fixtures
	b2d_fixtureDef.shape = &b2d_dynamicShape;
	
	//Default fixtures
	b2d_fixtureDef.density = den;
	b2d_fixtureDef.friction = fric;
	b2d_fixtureDef.restitution = rest;

	b2d_Body->CreateFixture(&b2d_fixtureDef);

	std::cout << "RADIUS: "
		<< b2d_dynamicShape.m_radius
		<< std::endl;
	
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
	
	b2d_fixtureDef.density = den;
	b2d_fixtureDef.friction = fric;
	b2d_fixtureDef.restitution = rest;
	//b2d_Body->CreateFixture(&b2d_fixtureDef);


}
void DynamicObject::setBody(b2Body* boxBody)
{

	b2d_Body = boxBody;
}

b2Body* DynamicObject::getBody()
{
	return b2d_Body;
}

void DynamicObject::setPos(b2Vec2 pos)
{
	b2d_bodyDef.position  = pos;
}

b2Vec2 DynamicObject::getPos() 
{
	return b2d_bodyDef.position;

}

void DynamicObject::updateSprite()
{
	//Setting the position from SFML to box2D
	
	b2Vec2 pos = b2d_Body->GetPosition();

	spriteRender.setPosition(pos.x * SCALE, pos.y * SCALE);
	
}

//Getter for destroye
void DynamicObject::isDestroyed(std::shared_ptr<b2World> world) {
	

	// Remove from Box2D world first
	 //Remove the object body from the world.
	b2Body* b2 = b2d_Body;
	world->DestroyBody(b2);
}
