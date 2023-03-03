#include <iostream>
#include "ShuntingYard.h"
#include "RPN.h"

#include "Application.h"
int main() {
    ShuntingYard shuntingYard;
    shuntingYard.convertInfix("5+6-3+4");
//    Application app;
//    app.run();
    return 0;
}
