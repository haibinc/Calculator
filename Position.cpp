//
// Created by Haibin Cao on 3/1/23.
//
#ifndef CALCULATOR_POSITION_CPP
#define CALCULATOR_POSITION_CPP
#include "Position.h"

template<class T, class S>
void Position::left(const T &obj1, S &obj2, float spacing)
{
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();
    obj2.setPosition(b1.left - b2.width - spacing, b1.top);
}

template<class T, class S>
void Position::right(const T &obj1, S &obj2, float spacing)
{
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();
    obj2.setPosition(b1.left + b2.width + spacing, b1.top);
}

template<class T, class S>
void Position::center(const T &obj1, S &obj2, float spacing)
{
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();
    obj2.setPosition(b1.left + b2.width/2, b1.top);
}

template<class T, class S>
void Position::bottom(const T &obj1, S &obj2, float spacing)
{
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();
    obj2.setPosition(b1.left, b1.top + b1.height + spacing);
}

#endif