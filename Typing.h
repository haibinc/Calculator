//
// Created by Haibin Cao on 2/28/23.
//

#ifndef TYPING_SFML_TYPING_H
#define TYPING_SFML_TYPING_H
#include <iostream>
#include "ShuntingYard.h"
#include "RPN.h"
#include "SFML/Graphics.hpp"
#include "ResourceHandler.h"
#include "ResourceHolder.h"

class Typing : public sf::Drawable
{
private:
    sf::Text text;
    std::string string = "0";
    ShuntingYard shuntingYard;
    RPN rpn;
    bool full = false;
public:
    Typing();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void loadFont();
    void setPosition(float x, float y);
    void typingPosition();
    void deletingPosition();
    void calculate();
    void setString(const std::string& string);
    void addChar(char letter);
    std::string getString();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //TYPING_SFML_TYPING_H
