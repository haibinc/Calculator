//
// Created by Haibin Cao on 3/2/23.
//

#include "RPN.h"

RPN::RPN()
{

}

int RPN::convertPostfix(const std::string string)
{
    int answer = 0;
    int secondNum = 0;
    for (int i = 0; i < string.size(); ++i)
    {
        if(std::isdigit(string[i]))
        {
            equationStack.push(string[i]);
        }
        else if(Operator(string[i]) < endEnum && equationStack.size() >= 2)
        {
            while(equationStack.size() >= 2)
            {
                secondNum = int(equationStack.top() - '0');
                equationStack.pop();
                switch(string[i])
                {
                    case '+':
                    {
                        answer = int(equationStack.top() - '0') + secondNum;
                        break;
                    }
                    case '-':
                    {
                        answer = int(equationStack.top() - '0') - secondNum;
                        break;
                    }
                    case '*':
                    {
                        answer = int(equationStack.top() - '0') * secondNum;
                        break;
                    }
                    case '/':
                    {
                        answer = int(equationStack.top() - '0') / secondNum;
                        break;
                    }
                    case '^':
                    {
                        answer = pow(answer = int(equationStack.top() - '0'), secondNum);
                        break;
                    }
                }
                equationStack.pop();
                std::cout << "answer: " << answer << std::endl;
                equationStack.push(answer + '0');
            }
        }
        else
        {
            assert(Operator(string[i]) < endEnum);
            assert(equationStack.size() >= 2);
        }
    }
    return answer;
}
