//
// Created by Haibin Cao on 3/2/23.
//

#ifndef CALCULATOR_SHUNTINGYARD_H
#define CALCULATOR_SHUNTINGYARD_H
#include <iostream>
#include "operatorPrecedence.h"
#include <stack>
#include <queue>

class ShuntingYard
{
private:
    std::queue<char> numQueue;
    std::stack<char> operatorStack;
public:
    ShuntingYard();
    void convertInfix(const std::string& string);
    bool higherPrecedence(char oper1, char oper2);
};


#endif //CALCULATOR_SHUNTINGYARD_H
