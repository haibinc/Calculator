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
        if(event.text.unicode == '\b')
        {
            if(string.size() > 0)
            {
                string.pop_back();
            }
        }
        else if(event.text.unicode == 13)
        {
            addChar('\n');
        }
        else if(event.text.unicode < 128)
        {
            addChar(event.text.unicode);
        }
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
    text.setCharacterSize(155);
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