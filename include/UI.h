#pragma once
#include "StaticObject.h"
#include "DynamicObject.h"
class UI : public virtual StaticObject, public virtual DynamicObject //Adding the use of a virtual to prevent ambugurity and inheritance issues
{
private:

public:
	UI() = default;
	~UI() = default;




};

