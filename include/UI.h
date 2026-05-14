#pragma once
#include "StaticObject.h"
#include "DynamicObject.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
//: virtual StaticObject, public virtual DynamicObject //Adding the use of a virtual to prevent ambugurity and inheritance issues
class UI 
{
private:
	
	sf::Text txt_Text;//the text
	sf::Font f_font;//the font of the text

public:
	UI(int i, std::string texT, sf::Vector2f pos) {
		
		
		if (!f_font.loadFromFile("angry-birds.ttf")) {
			std::cout << "Error" << std::endl;
		};
			
		txt_Text.setString(texT);
		txt_Text.setFont(f_font);
		txt_Text.setCharacterSize(i);
		txt_Text.setPosition(pos);
	};

	sf::Text getText() {
		return txt_Text;
	}
	~UI() = default;
	//UI(sf::RenderWindow &screen);
	UI( std::string location, std::string text, int textSize, sf::Vector2f position);
	//str text, str location, int textSize, vector2f position, &window

	//void setTextSize(int textSize);

	//void setText(std::string location);
	sf::Font gettxt_Text() {
		return f_font;
		std::cout << "Text is called debug" << std::endl;
	}; //return the string


};

