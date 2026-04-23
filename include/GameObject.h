#pragma once
#include <iostream>
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
class GameObject {
private:


public:
	GameObject() = default;
	//~GameObject() = default;
	~GameObject() {

		std::cout << "Ultimate DEATH" << std::endl;
	};
//add a pure virtual void
//virtual void Render() = 0;--REMEMBER TO DECLARE IN CHILDREN CLASSES 







};
