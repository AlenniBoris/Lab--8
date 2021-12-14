#ifndef LAB_8_STACK_H

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
    Stack<T> &operator=(const Stack<T>& stack);
    friend bool operator==(Stack<T>& F_stack,Stack<T>& S_stack);
    T operator[](int i);


    ~Stack();
};

template<typename T>
int Stack<T>::getSize() {
    return size;
}
template<typename T>
T Stack<T>::top() {
    return Base_St[size - 1];
}

template<typename T>
T Stack<T>::pop() {
    --size;
    (*this).Base_St= Base_St;
    return Base_St[size];
}

template<typename T>
void Stack<T>::push(T value) {
    if (size != 0) {
        T* Temp_St = new T[size];
        for (int i = 0; i < size; i++) {
            Temp_St[i] = Base_St[i];
        }
        delete[] Base_St;
        Base_St = new T[++size];
        for (int j = 0; j < size - 1; j++) {
            Base_St[j] = Temp_St[j];
        }
        delete[] Temp_St;
    } else {
        delete[] Base_St;
        Base_St = new T[++size];
    }
    Base_St[size - 1] = value;
}

template<typename T>
void Stack<T>::print(std::ostream &out) {
    for (int i = 0; i < size; i++) {
        out << " | " << Base_St[i] << " | ";
    }
}

template<typename T>
bool Stack<T>::isEmpty() {
    return size;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] Base_St;

}

template <typename T>
void operator<<(Stack<T>& stack, T elem) {
    stack.push(elem);
}

template <typename T>
void operator>>(Stack<T>& stack, T elem) {
    elem = stack.pop();
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &stack) {
    this->size = stack.size;
    delete[] this->Base_St;
    this->stackBase = new T[stack.size];
    for (int i = 0; i < stack.size; ++i) {
        &Base_St[i] = &(stack.stackBase[i]);
    }
    return *this;
}

template <typename T>
bool operator<(Stack<T>& F_stack,Stack<T>& S_stack) {
    return (F_stack.size < S_stack.size);
}

template <typename T>
bool operator>(Stack<T>& F_stack,Stack<T>& S_stack) {
    return (F_stack.size > S_stack.size);
}

template <typename T>
bool operator==(Stack<T>& F_stack,Stack<T>& S_stack) {
    return (F_stack.size == S_stack.size);
}

template <typename T>
T Stack<T>::operator[](int i) {
    return Base_St[size-i];
}




#endif //LAB_8_STACK_H
