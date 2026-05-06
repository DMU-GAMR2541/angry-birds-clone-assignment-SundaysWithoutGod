#include "Pig.h"

//Setting the health to an accessible varible
void Pig::setHealth(int pigHealth) {

	i_Health = pigHealth;

	}	

//Getter for the health
int Pig::getHealth() {

	return i_Health;
}

//If the pig is hit then take damage from health and if health is less than 0 the bird is destroyed
void Pig::isHit(int damage)
{
	if (damage < 0) return;
	i_Health -= damage;
	if (i_Health <= 0) {
		i_Health = 0;
		b_Destroyed = true;
	}
}

//Getter for destroyed bool
bool Pig::isDestroyed()
{
	return b_Destroyed;
}
