//
// Created by Haibin Cao on 3/2/23.
//

#ifndef CALCULATOR_RPN_H
#define CALCULATOR_RPN_H
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include "operatorPrecedence.h"

class RPN
{
private:
    std::stack<float> equationStack;
public:
    RPN();
    float convertPostfix(std::queue<std::string>& queue);
};


#endif //CALCULATOR_RPN_H
