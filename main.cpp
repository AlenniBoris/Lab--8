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
    stack.push(18);
    stack.push(-133);
    stack.push(172.7882);
    stack.push(7227);

    std::cout << "Your stack:\n";
    stack.print(std::cout);


    std::cout << "\nTop element " << stack.top() << std::endl;
    std::cout << "Stack size: " << stack.getSize() << std::endl;
    std::cout << "Stack fourth element: " << stack[5] << std::endl;

    return 0;
}
