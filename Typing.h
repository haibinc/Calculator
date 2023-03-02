//
// Created by Haibin Cao on 2/28/23.
//

#ifndef TYPING_SFML_TYPING_H
#define TYPING_SFML_TYPING_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "ResourceHandler.h"
#include "ResourceHolder.h"

class Typing : public sf::Drawable
{
private:
    sf::Text text;
    std::string string;
public:
    Typing();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void loadFont();
    void setPosition(float x, float y);
    void setString(const std::string& string);
    void addChar(char letter);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //TYPING_SFML_TYPING_H
