#include <iostream>
#include "ShuntingYard.h"
#include "RPN.h"

#include "Application.h"
int main() {
    ShuntingYard shuntingYard;
    RPN rpn;
    std::cout << rpn.convertPostfix(shuntingYard.convertInfix("12600/6-8")) << std::endl;
//    Application app;
//    app.run();
    return 0;
}
