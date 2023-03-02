//
// Created by Haibin Cao on 3/1/23.
//

#ifndef CALCULATOR_POSITION_H
#define CALCULATOR_POSITION_H
#include <iostream>
#include "SFML/Graphics.hpp"

class Position
{
public:
    template<class T, class S>
    static void left(const T& obj1, S& obj2, float spacing = 0);
    template<class T, class S>
    static void right(const T& obj1, S& obj2, float spacing = 0);
    template<class T, class S>
    static void center(const T& obj1, S& obj2, float spacing = 0);
    template<class T, class S>
    static void bottom(const T& obj1, S& obj2, float spacing = 0);
};
#include "Position.cpp"

#endif //CALCULATOR_POSITION_H
