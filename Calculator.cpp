#include "Calculator.h"

double Calculate(double FirstNumber, double SecondNumber, char Operation) {
    if (Operation == '*') {
        return (FirstNumber * SecondNumber);
    }
    if (Operation == '-') {
        return (FirstNumber - SecondNumber);
    }
    if (Operation == '+') {
        return (FirstNumber + SecondNumber);
    }
    if (Operation == '^') {
        return (pow(FirstNumber, SecondNumber));
    }
    if (Operation == '/') {
        if (SecondNumber == 0) {
            throw std::runtime_error("Can't divide by zero");
        }
        return (FirstNumber / SecondNumber);
    }
    return 0;
}

bool Operation(char OperationType) {
    return (OperationType == '*') || (OperationType == '-') || (OperationType == '+') ||
           (OperationType == '^') || (OperationType == '/');
}

int OperationPriority(char OperationType) {
    if ((OperationType == '+') || (OperationType == '-')) {
        return 1;
    }
    if ((OperationType == '*') || (OperationType == '/')) {
        return 2;
    }
    if (OperationType == '^') {
        return 3;
    }
    return -1;
}

double CalculateExpression(string MathEquation) {
    string Temp_str{};
    for (char i: MathEquation) {
        if (i != ' ') {
            Temp_str += i;
        }
    }
    MathEquation = Temp_str;
    Stack<char> Symbols;
    Stack<double> Numbers;
    for (size_t j = 0; j < MathEquation.size(); ++j) {
        if (Operation(MathEquation[j])) {
            while (!(Symbols.isEmpty()) && OperationPriority(MathEquation[j]) <= OperationPriority(Symbols.top())) {
                double S_Number = Numbers.pop();
                double F_Number = Numbers.pop();
                Numbers.push(Calculate(F_Number, S_Number, Symbols.pop()));
            }
            Symbols.push(MathEquation[j]);
        } else {
            if (MathEquation[j] == '(') {
                if (MathEquation[j + 1] == '-') {
                    ++j;
                    while (MathEquation[j] != ')') {
                        Temp_str = "";
                        Temp_str += MathEquation[j];
                        ++j;
                    }
                    Numbers.push(-1 * stod(Temp_str));
                } else {
                    Symbols.push(MathEquation[j]);
                }
            } else if (MathEquation[j] == ')') {
                while (Symbols.top() != '(') {
                    double S_Number = Numbers.pop();
                    double F_Number = Numbers.pop();
                    Numbers.push(Calculate(F_Number, S_Number, Symbols.pop()));
                }
                Symbols.pop();
            } else {
                Temp_str = "";
                while (!Operation(MathEquation[j]) && MathEquation[j] != ')' && MathEquation[j] != '(' &&
                       j != MathEquation.size()) {
                    Temp_str += MathEquation[j];
                    j++;
                }
                --j;
                Numbers.push(stod(Temp_str));
            }
        }
    }
    while (!Symbols.isEmpty()) {
        double S_Number = Numbers.pop();
        double F_Number = Numbers.pop();
        Numbers.push(Calculate(F_Number, S_Number, Symbols.pop()));
    }
    return Numbers.top();
}

void Solution() {
    string MathEquation;
    cout << "Enter your expression:" << endl;
    getline(cin, MathEquation);
    cout << "It is equal to:" << endl;
    cout << CalculateExpression(MathEquation) << endl;
}