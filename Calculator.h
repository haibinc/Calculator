//
// Created by Haibin Cao on 2/28/23.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H
#include "SFML/Graphics.hpp"
#include "Typing.h"
#include "Buttons.h"
#include "Position.h"
#include <iostream>

class Calculator : public sf::Drawable
{
private:
//    char symbols[19] = {'C', 'n', '%', '/',
//                        '7', '8', '9', 'X',
//                        '4', '5', '6', '-',
//                        '1', '2', '3', '+',
//                        '0', '.', '='};
    Typing input;
    char operator_Symbols[5] = {'/', 'X', '-', '+', '='};
    char top_Symbols[3] = {'C', 'N', '%'};
    char num_Symbols[9] = {'7', '8', '9', '4', '5', '6', '1', '2', '3'};
    std::vector<Buttons> operator_Buttons;
    std::vector<Buttons> top_Buttons;
    std::vector<Buttons> num_Buttons;
public:
    Calculator();
    void setup();
    void setPosition(float x, float y);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CALCULATOR_CALCULATOR_H
