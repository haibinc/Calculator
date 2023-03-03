//
// Created by Haibin Cao on 3/2/23.
//

#include "ShuntingYard.h"

ShuntingYard::ShuntingYard()
{
}

void ShuntingYard::convertInfix(const std::string& string)
{
    for (int i = 0; i < string.size(); ++i)
    {
        if(std::isdigit(string[i]))
        {
            numQueue.push(string[i]);
        }
        else if (Operator(string[i]) < endEnum)
        {
            operatorStack.push(string[i]);
            if(operatorStack.size() > 1)
            {
//                std::cout << "stack top " << operatorStack.top() << std::endl;
                if(higherPrecedence(string[i], operatorStack.top()))
                {
//                    std::cout << "stack top " << operatorStack.top() << std::endl;
//                    std::cout << "queue back " << numQueue.back() << std::endl;
                    numQueue.push(operatorStack.top());
                    operatorStack.pop();
                    operatorStack.push(string[i]);
//                    std::cout << "stack top " << operatorStack.top() << std::endl;
//                    std::cout << "queue back " << numQueue.back() << std::endl;
                }
                else
                {
//                    std::cout << "stack top " << operatorStack.top() << std::endl;
//                    std::cout << "queue back " << numQueue.back() << std::endl;
                    numQueue.push(operatorStack.top());
                    operatorStack.pop();
                    operatorStack.push(string[i]);
//                    std::cout << "stack top " << operatorStack.top() << std::endl;
//                    std::cout << "queue back " << numQueue.back() << std::endl;
                }
            }
        }
        else
        {
            assert(Operator(string[i]) < endEnum);
        }
        std::cout << numQueue.back();
    }
}

bool ShuntingYard::higherPrecedence(char oper1, char oper2)
{
    if((Operator(oper1) == '*' || Operator(oper1) == '/') && (Operator(oper2) == '+' || Operator(oper2) == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}