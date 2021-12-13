#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

    Stack<double> stack;
    cout << stack.isEmpty() << endl;
    stack << 5;
    cout << stack.getSize() << " ";
    stack.push(5.6);
    cout << stack.getSize() << " ";
    stack.push(3.24);
    cout << stack.getSize() << " ";
    stack.push(9.712);
    cout << stack.getSize() << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    stack.print(cout);
//    Stack<int> stack;
//
//    double test = 1133;
//
//    stack.push(5);
//    stack.push(18);
//    stack.push(21);
//    stack.push(16);
//    stack.push(47);
//    stack.push(-16);
//
//    std::cout << "Your stack: " << std::endl;
//    stack.isEmpty();

    return 0;
}
