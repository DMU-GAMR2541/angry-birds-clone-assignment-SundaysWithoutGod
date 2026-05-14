#include "Bird.h"

void Bird::setDamage(int birdDamage)
{
	i_DamageGiven = birdDamage;

}

int Bird::getDamage()
{
	return i_DamageGiven;
}

void Bird::isHit()
{
	//return what is hit

}

void Bird::isDestroyed(std::shared_ptr<b2World> world)
{


}



