#pragma once
#include "DynamicObject.h"
class Pig : public DynamicObject
{
private:

	int i_Health;
	bool b_Destroyed;
	

public:

	Pig() = default;
	//~Pig() = default;
	~Pig() {

		std::cout << "Pig DEATH" << std::endl;
	};
	
};

