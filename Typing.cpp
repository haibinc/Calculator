//
// Created by Haibin Cao on 2/28/23.
//
#include "Typing.h"

Typing::Typing()
{
    loadFont();
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(event.type == sf::Event::TextEntered)
    {
        std::cout << event.text.unicode << std::endl;
        if(string == "0")
        {
            string.pop_back();
        }
        if(event.text.unicode == '\b')
        {
            if(string.size() > 0)
            {
                string.pop_back();
            }
            deletingPosition();
        }
        else if(event.text.unicode == 10)
        {
            calculate();
        }
        else if(event.text.unicode >= 42 && event.text.unicode <= 57 && !full)
        {
            addChar(event.text.unicode);
            typingPosition();
        }
        else if(event.text.unicode == 96)
        {
            string.clear();
        }
    }
    else if(string.empty())
    {
        string = "0";
        text.setPosition(600, 270);
        full = false;
    }
}

void Typing::calculate()
{
    text.setPosition(10, 270);
    string =  std::to_string(rpn.convertPostfix(shuntingYard.convertInfix(string)));
}

void Typing::typingPosition()
{
    if((text.getGlobalBounds().left + text.getGlobalBounds().width) + 100 >= 700)
    {
        text.setPosition(text.getGlobalBounds().left - 150, text.getPosition().y);
    }
    else if(text.getGlobalBounds().left - 100 <= 0)
    {
        full = true;
    }
}

void Typing::deletingPosition()
{
    if((text.getGlobalBounds().left + text.getGlobalBounds().width) + 100 <= 700)
    {
        text.setPosition(text.getGlobalBounds().left + 150, text.getPosition().y);
    }
}

void Typing::update()
{
    text.setString(string);
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);
}


void Typing::loadFont()
{
    ResourceHandler<Font, sf::Font>::load(Font::OPEN_SANS, "OpenSans-Bold.ttf");
    text.setFont(ResourceHandler<Font, sf::Font>::get(Font::OPEN_SANS));
    text.setCharacterSize(90);
}

void Typing::setPosition(float x, float y)
{
    text.setPosition(x, y);
}

void Typing::addChar(char letter)
{
    string += letter;
}

void Typing::setString(const std::string& string)
{
    text.setString(string);
}

std::string Typing::getString()
{
    return string;
}