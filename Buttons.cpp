//
// Created by Haibin Cao on 2/28/23.
//

#include "Buttons.h"

Buttons::Buttons()
{
    button.setRadius(25);
    text.setFont(ResourceHandler<Font, sf::Font>::get(OPEN_SANS));
    text.setFillColor(sf::Color::Black);
}

void Buttons::setFillColor(sf::Color color)
{
    button.setFillColor(color);
}

void Buttons::setText(const std::string& string)
{
    text.setString(string);
}

void Buttons::setPosition(const sf::Vector2f& position)
{
    button.setPosition(position);
    text.setPosition(getGlobalBounds().left + button.getRadius()/1.5, getGlobalBounds().height + button.getRadius()/3);
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