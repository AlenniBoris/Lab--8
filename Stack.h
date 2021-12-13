#ifndef LAB_8_STACK_H
#define LA8_8_STACK_H

#include <ostream>


template<typename T>
class Stack {
private:
    T* Base_St = new T[0];
    int size = 0;
public:

    int getSize();
    T top();
    T pop();
    void push(T value);
    void print(std::ostream& out);
    bool isEmpty();


    friend Stack<T> operator <<(Stack<T>& stack,T elem);
    friend Stack<T> operator >>(Stack<T>& stack,T elem);
    friend bool operator<(Stack<T>& F_stack,Stack<T>& S_stack);
    friend bool operator>(Stack<T>& F_stack,Stack<T>& S_stack);
    Stack<T> &operator=(Stack<T>& stack);
    friend bool operator==(Stack<T>& F_stack,Stack<T>& S_stack);
    T operator[](int i);


    ~Stack();


};




#endif //LAB_8_STACK_H
