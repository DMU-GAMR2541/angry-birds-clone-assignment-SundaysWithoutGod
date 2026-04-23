#pragma once
#include "DynamicObject.h"
class Bird : public DynamicObject
{
private:
	bool b_Destroyed;
	int i_Speed;
	float i_Weight;
	int i_DamageGiven;


public:
	Bird() = default;
	~Bird() = default;


};

