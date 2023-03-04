#include <iostream>
#include "ShuntingYard.h"
#include "RPN.h"

#include "Application.h"
int main() {
    ShuntingYard shuntingYard;
    RPN rpn;
    std::cout << rpn.convertPostfix(shuntingYard.convertInfix("5+6-3+4")) << std::endl;
//    Application app;
//    app.run();
    return 0;
}
