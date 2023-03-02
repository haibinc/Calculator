//
// Created by Haibin Cao on 2/28/23.
//

#include "Application.h"

Application::Application()
{
loadFont();
}

void Application::run()
{
    sf::RenderWindow window(sf::VideoMode(700, 1200), "SFML Application");
    Calculator calc;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }
        window.clear();
        window.draw(calc);
        window.display();
    }
}

void Application::loadFont()
{
    ResourceHandler<Font, sf::Font>::load(Font::OPEN_SANS, "OpenSans-Bold.ttf");
}

void Application::loadTexture()
{

}
