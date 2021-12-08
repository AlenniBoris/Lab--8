//
// Created by Xiaomi on 07.12.2021.
//

#include "Stack.h"

int Stack::getSize() {
    return size;
}

double Stack::top() {
    return stackBase[size - 1];
}

double Stack::pop() {
    --size;
    return stackBase[size];
}

void Stack::push(double value) {
    if (size != 0) {
        double* temp = new double[size];
        for (int i = 0; i < size; i++) {
            temp[i] = stackBase[i];
        }
        delete[] stackBase;
        // создаем старый новый массив, но больше размером, куда закидываем переменную
        stackBase = new double[++size];
        for (int j = 0; j < size - 1; j++) {
            stackBase[j] = temp[j];
        }
        delete[] temp;
    } else {
        delete[] stackBase;
        stackBase = new double[++size];
    }
    stackBase[size - 1] = value;
}

void Stack::print(std::ostream &out) {
    for (int i = 0; i < size; i++) {
        out << " | " << stackBase[i] << " | ";
    }
}

bool Stack::isEmpty() {
    return size;
}

Stack::~Stack() {
    delete[] stackBase;
}

void operator<<(Stack& stack, double el) {
    stack.push(el);
}

void operator>>(Stack &stack, double el) {
    stack.pop();
}

Stack Stack::operator=(Stack &stack) {
    this->size = stack.size;
    for (int i = 0; i < stack.size; ++i) {
        this->stackBase[i]=stack.stackBase[i];
    }

    return *this;
}

bool operator<(Stack &stack,Stack& stack1) {
    return (stack.size < stack1.size);
}

bool operator>(Stack &stack,Stack& stack1) {
    return (stack.size > stack1.size);
}

bool operator==(Stack &stack,Stack& stack1) {
    return (stack.size == stack1.size);
}

double Stack::operator[](int i) {
    Stack stack = *this;
    for (int j = 0; j < i-1; ++j) {
        stack.pop();
    }
    return stack.pop();
}




