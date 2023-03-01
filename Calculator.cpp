//
// Created by Haibin Cao on 2/28/23.
//

#include "Calculator.h"

Calculator::Calculator()
{
    Buttons button, button2;
    button.setFillColor(sf::Color::White);
    button2.setFillColor(sf::Color::White);
    button.setText("1");
    button2.setText("2");
    button.setPosition(sf::Vector2f(50,50));
    button2.setPosition(sf::Vector2f(150,50));
}