#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

//    Stack<double> stack;
//    cout << stack.isEmpty() << endl;
//    stack << 5;
//    cout << stack.getSize() << " ";
//    stack.push(5.6);
//    cout << stack.getSize() << " ";
//    stack.push(3.24);
//    cout << stack.getSize() << " ";
//    stack.push(9.712);
//    cout << stack.getSize() << endl;
//    cout << stack.pop() << endl;
//    cout << stack.top() << endl;
//    stack.print(cout);
    Stack<int> stack;

    stack.push(5);
    stack.push(18);
    stack.push(21);
    stack.push(16);
    stack.push(47);
    stack.push(-16);
    stack.push(0);

    Stack<int> stack2;

    stack2.push(42);
    stack2.push(-16);
    stack2.push(2);
    stack2.push(1);
    stack2.push(7);
    stack2.push(6);


    cout << "Your stack: " <<endl;
    stack.print(cout);
    cout << "\nYour stack size: " << stack.getSize() << endl;
    cout << "Your top stack element: " << stack.top() << endl;
    stack.pop();
    cout << "Your stack after pop: " <<endl;
    stack.print(cout);
    cout << "\nYour stack size: " << stack.getSize() << endl;
    cout << "Your stack second element: " << stack[1] << endl;
    cout << "Stack is not empty: " << stack.isEmpty() << endl;
    cout << "Logical: Equal:" << (&stack==&stack2) << " Less:" << (&stack < &stack2) << " Bigger:" << (&stack > &stack2);






    return 0;
}
