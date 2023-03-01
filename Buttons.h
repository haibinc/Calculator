//
// Created by Haibin Cao on 2/28/23.
//

#ifndef CALCULATOR_BUTTONS_H
#define CALCULATOR_BUTTONS_H
#include "SFML/Graphics.hpp"
#include "ResourceHolder.h"
#include "ResourceHandler.h"

class Buttons : public sf::Drawable
{
private:
    sf::CircleShape button;
   sf::Text text;
public:
    Buttons();
    void setFillColor(sf::Color color);
    void setText(const std::string& string);
    void setPosition(const sf::Vector2f& position);
    sf::FloatRect getGlobalBounds() const;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CALCULATOR_BUTTONS_H
