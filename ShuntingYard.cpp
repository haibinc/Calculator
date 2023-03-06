//
// Created by Haibin Cao on 3/2/23.
//

#include "ShuntingYard.h"

ShuntingYard::ShuntingYard()
{
}

std::queue<std::string>& ShuntingYard::convertInfix(const std::string& string)
{
    std::string temp;
    for (int i = 0; i < string.size(); ++i)
    {
        if(std::isdigit(string[i]))
        {
            temp = string[i];
            int index = 0;
            while(std::isdigit(string[i + (index+1)]))
            {
                index++;
                temp += string[i+index];
//                std::cout << "temp: " << temp << std::endl;
            }
            i = i + index;
            numQueue.push(temp);
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
                    operatorStack.push(string[i]);
                }
                else
                {
                    while(!operatorStack.empty() && !higherPrecedence(string[i], operatorStack.top()))
                    {
                        temp = operatorStack.top();
                        numQueue.push(temp);
                        operatorStack.pop();
                    }
                    operatorStack.push(string[i]);
                }
            }
        }
        else
        {
            assert(Operator(string[i]) < endEnum);
        }
        while(i == string.size()-1 && !operatorStack.empty())
        {
            temp = operatorStack.top();
            numQueue.push(temp);
            operatorStack.pop();
//            std::cout << "stack size: " << operatorStack.size() << std::endl;
//            std::cout << "queue size: " << numQueue.size() << std::endl;
        }
    }
//   while(!numQueue.empty())
//   {
//       std::cout << "element: " << numQueue.front() << std::endl;
//       numQueue.pop();
//   }
//   std::cout << std::endl;
   return numQueue;
}

bool ShuntingYard::higherPrecedence(char oper1, char oper2)
{
    if((Operator(oper1) == '*' || Operator(oper1) == '/') && (Operator(oper2) == '+' || Operator(oper2) == '-'))
    {
        return true;
    }
    else if (Operator(oper1) == '^' && Operator(oper2) != '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}