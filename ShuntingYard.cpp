//
// Created by Haibin Cao on 3/2/23.
//

#include "ShuntingYard.h"

ShuntingYard::ShuntingYard()
{
}

std::string ShuntingYard::convertInfix(const std::string& string)
{
    std::string temp;
    for (int i = 0; i < string.size(); ++i)
    {
        if(std::isdigit(string[i]))
        {
            numQueue.push(string[i]);
        }
        else if (Operator(string[i]) < endEnum)
        {
            if(operatorStack.empty())
            {
                operatorStack.push(string[i]);
            }
            else if(!operatorStack.empty())
            {
                if(higherPrecedence(string[i], operatorStack.top()))
                {
                    numQueue.push(string[i]);
                }
                else
                {
//                    std::cout << "stack top: " << operatorStack.top() << std::endl;
                    numQueue.push(operatorStack.top());
//                    std::cout << "queue back: " << numQueue.back() << std::endl;
                    operatorStack.pop();
                    operatorStack.push(string[i]);
//                    std::cout << "stack top after pop: " << operatorStack.top() << std::endl;
//                    std::cout << "stack size: " << operatorStack.size() << std::endl;
                }
            }
        }
        else
        {
            assert(Operator(string[i]) < endEnum);
        }
        while(i == string.size()-1 && !operatorStack.empty())
        {
            numQueue.push(operatorStack.top());
            operatorStack.pop();
//            std::cout << "stack size: " << operatorStack.size() << std::endl;
//            std::cout << "queue size: " << numQueue.size() << std::endl;
        }
    }
   while(!numQueue.empty())
   {

       temp += numQueue.front();
       numQueue.pop();
   }
   return temp;
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