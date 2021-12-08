#include <iostream>
#include "Stack.h"

int main() {

    Stack stack;

    double test = 1133;

    std::cout << stack.isEmpty();

    stack << test;

    stack.push(3);

    stack.push(12);
    stack.push(155);

    stack.print(std::cout);

    std::cout << "\nTop element " << stack.top();

    std::cout << "\n";
    stack.pop();
    stack.print(std::cout);


    return 0;
}
