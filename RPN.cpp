//
// Created by Haibin Cao on 3/2/23.
//

#include "RPN.h"

RPN::RPN()
{

}

float RPN::convertPostfix(std::queue<std::string>& queue)
{
    float answer = 0;
    float num = 0;
    while(!queue.empty())
    {
        if(std::isdigit(queue.front()[0]))
        {
            num = std::stof(queue.front());
            equationStack.push(num);
            std::cout << "second num: " << num << std::endl;
            queue.pop();
        }
        else if(Operator(queue.front()[0]) < endEnum)
        {
            assert(equationStack.size() >= 2);
            std::cout << "operator: " << queue.front()[0] << std::endl;
            switch(queue.front()[0])
            {
                case '+':
                {
                    num = equationStack.top();
                    equationStack.pop();
                    float temp = equationStack.top();
                    std::cout << "temp + num: " << temp << " + " << num << std::endl;
                    answer = temp + num;
                    equationStack.pop();
                    std::cout << "answer: " << answer << std::endl;
                    equationStack.push(answer);
                    break;
                }
                case '-':
                {
                    num = equationStack.top();
                    equationStack.pop();
                    float temp = equationStack.top();
                    std::cout << "temp - num: " << temp << " - " << num << std::endl;
                    answer = temp - num;
                    equationStack.pop();
                    std::cout << "answer: " << answer << std::endl;
                    equationStack.push(answer);
                    break;
                }
                case '*':
                {
                    num = equationStack.top();
                    equationStack.pop();
                    float temp = equationStack.top();
                    std::cout << "temp * num: " << temp << " * " << num << std::endl;
                    answer = temp * num;
                    equationStack.pop();
                    std::cout << "answer: " << answer << std::endl;
                    equationStack.push(answer);
                    break;
                }
                case '/':
                {
                    num = equationStack.top();
                    equationStack.pop();
                    float temp = equationStack.top();
                    std::cout << "temp /` num: " << temp << " / " << num << std::endl;
                    answer = temp / num;
                    equationStack.pop();
                    std::cout << "answer: " << answer << std::endl;
                    equationStack.push(answer);
                    break;
                }
            }
            queue.pop();
        }
    }
    return answer;
}