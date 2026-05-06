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
	//Destroy the sprite and the box2d body

}

