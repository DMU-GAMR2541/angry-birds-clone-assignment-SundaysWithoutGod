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
void Pig::isHit()
{ 
	if ( i_Health > 0) return;
	i_Health - 10;
	if (i_Health <= 0) {
		i_Health = 0;
		b_Destroyed = true;
	}
}


