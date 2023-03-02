//
// Created by Haibin Cao on 2/28/23.
//

#include "Calculator.h"

Calculator::Calculator()
{
    setup();
}

void Calculator::setup()
{
    input.setPosition(570, 200);
    input.setString("0");
    for (int i = 0; i < sizeof(operator_Symbols); ++i)
    {
        Buttons button;
        operator_Buttons.push_back(button);
        if(i == 0)
        {
            operator_Buttons[i].setPosition(550, 400);
            operator_Buttons[i].setFillColor(sf::Color(255, 165, 0));
            operator_Buttons[i].setText(operator_Symbols[i]);
        }
        else
        {
            operator_Buttons[i].setFillColor(sf::Color(255, 165, 0));
            operator_Buttons[i].setText(operator_Symbols[i]);
            Position::bottom(operator_Buttons[i-1], operator_Buttons[i], 25);
        }
    }
    for (int i = 0; i < sizeof(top_Symbols); ++i)
    {
        Buttons button;
        top_Buttons.push_back(button);
        if(i == 0)
        {
            top_Buttons[i].setPosition(70, 400);
            top_Buttons[i].setFillColor(sf::Color(192, 192, 192));
            top_Buttons[i].setText(top_Symbols[i]);
        }
        else
        {
            top_Buttons[i].setFillColor(sf::Color(192, 192, 192));
            top_Buttons[i].setText(top_Symbols[i]);
            Position::right(top_Buttons[i-1], top_Buttons[i], 25);
        }
    }
    for (int i = 0; i < sizeof(num_Symbols); ++i)
    {
        Buttons button;
        num_Buttons.push_back(button);
        if(i == 0)
        {
            num_Buttons[i].setPosition(70, 555);
            num_Buttons[i].setFillColor(sf::Color(105, 105, 105));
            num_Buttons[i].setText(num_Symbols[i]);
        }
        else
        {
            num_Buttons[i].setFillColor(sf::Color(105, 105, 105));
            num_Buttons[i].setText(num_Symbols[i]);
            Position::right(num_Buttons[i-1], num_Buttons[i], 25);
            if(i % 3 == 0)
            {
                std::cout << num_Symbols[i] << std::endl;
                Position::bottom(num_Buttons[i-3], num_Buttons[i], 25);
            }
        }
    }
}

void Calculator::setPosition(float x, float y)
{

}

void Calculator::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for (int i = 0; i < operator_Buttons.size(); ++i)
    {
        window.draw(operator_Buttons[i]);
    }
    for (int i = 0; i < top_Buttons.size(); ++i)
    {
        window.draw(top_Buttons[i]);
    }
    for (int i = 0; i < num_Buttons.size(); ++i)
    {
        window.draw(num_Buttons[i]);
    }

    window.draw(input);
}
