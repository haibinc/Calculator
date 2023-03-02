//
// Created by Haibin Cao on 2/28/23.
//

#include "Buttons.h"

Buttons::Buttons()
{
    button.setRadius(65);
    text.setFont(ResourceHandler<Font, sf::Font>::get(OPEN_SANS));
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(button.getRadius());
}

void Buttons::setFillColor(sf::Color color)
{
    button.setFillColor(color);
}

void Buttons::setText(char string)
{
    std::string temp;
    temp += string;
    text.setString(temp);
}

void Buttons::setText(const std::string& string)
{
    text.setString(string);
}

void Buttons::setPosition(const sf::Vector2f& position)
{
    button.setPosition(position);
    text.setPosition(getGlobalBounds().left + button.getRadius()/1.5, getGlobalBounds().top + button.getRadius()/3);
}

void Buttons::setPosition(float x, float y)
{
    button.setPosition(x, y);
    text.setPosition(getGlobalBounds().left + button.getRadius()/1.5, getGlobalBounds().top + button.getRadius()/3);
}

sf::FloatRect Buttons::getGlobalBounds() const
{
    return button.getGlobalBounds();
}

void Buttons::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(button);
    window.draw(text);
}