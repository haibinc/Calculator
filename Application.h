//
// Created by Haibin Cao on 2/28/23.
//

#ifndef CALCULATOR_APPLICATION_H
#define CALCULATOR_APPLICATION_H
#include "SFML/Graphics.hpp"
#include "ResourceHandler.h"
#include "ResourceHolder.h"
#include "Calculator.h"

class Application
{
private:

public:
    Application();
    void loadFont();
    void loadTexture();
    void run();
};


#endif //CALCULATOR_APPLICATION_H
