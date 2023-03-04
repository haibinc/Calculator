//
// Created by Haibin Cao on 3/2/23.
//

#ifndef CALCULATOR_RPN_H
#define CALCULATOR_RPN_H
#include <iostream>
#include <stack>
#include <cmath>
#include "operatorPrecedence.h"

class RPN
{
private:
    std::stack<char> equationStack;
public:
    RPN();
    int convertPostfix(const std::string string);
};


#endif //CALCULATOR_RPN_H
