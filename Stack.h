#ifndef DIMA_S_STACK_H
#define DIMA_S_STACK_H


#include <ostream>

class Stack {
private:
    double* stackBase = new double[0];
    int size = 0;

public:

    int getSize();
    double top();
    double pop();
    void push(double value);
    void print(std::ostream& out);
    bool isEmpty();
    friend void operator <<(Stack& stack,double el);
    friend void operator >>(Stack& stack,double el);
    Stack operator=(Stack& stack);

    friend bool operator<(Stack& stack,Stack& stack1);
    friend bool operator>(Stack& stack,Stack& stack1);
    friend bool operator==(Stack& stack,Stack& stack1);

    double operator[](int i);

    ~Stack();


};




#endif //DIMA_S_STACK_H
