#include "Calculator.h"

double Calculate(double FirstNumber, double SecondNumber, char Operation){
    if (Operation == '*'){
        return (FirstNumber * SecondNumber);
    }
    if (Operation == '-'){
        return (FirstNumber - SecondNumber);
    }
    if (Operation == '+'){
        return (FirstNumber + SecondNumber);
    }
    if (Operation == '^'){
        return (pow(FirstNumber, SecondNumber));
    }
    if (Operation == '/'){
        if (SecondNumber == 0){
            throw std::runtime_error("Can't divide by zero");
        }
        return (FirstNumber / SecondNumber);
    }
    return 0;
}
bool Operation(char OperationType){
    return  (OperationType == '*') || (OperationType == '-') || (OperationType == '+') ||
            (OperationType == '^') || (OperationType == '/');
}
int OperationPriority(char OperationType){
    if ((OperationType == '+') || (OperationType == '-')){
        return 1;
    }
    if ((OperationType == '*') || (OperationType == '/')){
        return 2;
    }
    if (OperationType == '^'){
        return 3;
    }
    return -1;
}
double CalculateEquation(string MathEquation){
    string Expression{};
    for(char ExpressionPart: MathEquation) {
        if(ExpressionPart != ' ')
            Expression += ExpressionPart;
    }
    MathEquation = Expression;
    Stack<double> Numbers;
    Stack<char> Operations;
    for (size_t i = 0; i < MathEquation.size(); ++i) {
        if (Operation(MathEquation[i])){
            while(!(Operations.isEmpty() && OperationPriority(Expression[i]) <= OperationPriority(Operations.top()))) {
                double SecondNumber = Numbers.pop();
                double FirstNumber = Numbers.pop();
                Numbers << Calculate(FirstNumber, SecondNumber, Operations.pop());
            }
            Operations << Expression[i];
        }else {
            if (MathEquation[i] == '('){
                if (MathEquation[i+1] == '-'){
                    ++i;
                    Expression = "";
                    while (MathEquation[i] != ')'){
                        Expression += MathEquation[i];
                        ++i;
                    }
                    Numbers << std::stod(Expression);
                } else{
                    Operations << MathEquation[i];
                }
            }
            else if(MathEquation[i] == ')'){
                while (Operations.top() != '('){
                    double SecondNumber = Numbers.pop();
                    double FirstNumber = Numbers.pop();
                    Numbers << Calculate(FirstNumber, SecondNumber, Operations.pop());
                }
                Operations.pop();
            }
            else{
                Expression = "";
                while (!Operation(MathEquation[i]) && MathEquation[i]!= ')' && MathEquation[i] != '(' &&  i != MathEquation.size()){
                    Expression += MathEquation[i];
                    ++i;
                }
                --i;
                Numbers << std::stod(Expression);
            }
        }

    }
    while (!(Operations.isEmpty())){
        double SecondNumber = Numbers.pop();
        double FirstNumber = Numbers.pop();
        Numbers << Calculate(FirstNumber, SecondNumber, Operations.pop());
    }
    return Numbers.top();
}
