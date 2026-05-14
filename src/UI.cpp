#include "UI.h"

//UI::UI(sf::RenderWindow& screen)
//{
//	if (!f_font.loadFromFile("../assests/fonts/angry-birds-1.ttf")) {
//		std::cout << "Texture NOT loadiing" << std::endl;
//
//	}
//	else
//	{
//		txt_Text.setFont(f_font);
//		//setting the origins-taking it from the corner to the center point
//		txt_Text.setOrigin(txt_Text.getLocalBounds().getSize().x / 2.0f, txt_Text.getLocalBounds().getSize().y / 2.0f);
//	}
//
//	txt_Text.setPosition(10.0f, 10.0f);
//
//}

UI::UI( std::string location, std::string text, int textSize, sf::Vector2f position)
{
	if (!f_font.loadFromFile("../assets/fonts/angry-birds.ttf")) {
		std::cout << "Texture NOT loadiing" << std::endl;

	}
	else
	{
		txt_Text.setFont(f_font);
		txt_Text.setCharacterSize(textSize);
		//setting the origins-taking it from the corner to the center point
		txt_Text.setOrigin(txt_Text.getLocalBounds().getSize().x / 2.0f, txt_Text.getLocalBounds().getSize().y / 2.0f);
	}

	txt_Text.setPosition(position.x, position.y);


}



//void UI::setText(std::string location)
//{
//	if (!font.loadFromFile(location)) {
//		std::cout << "Texture NOT loadiing" << std::endl;
//
//	}
//	else
//	{
//		Text.setFont(font);
//	}
//}

