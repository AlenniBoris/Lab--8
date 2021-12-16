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
    for (unsigned int i = 0; i < MathEquation.size(); ++i) {
        if (Operation(MathEquation[i])){
            while(!(Operations.isEmpty()) && OperationPriority(MathEquation[i]) <= OperationPriority(Operations.top())){
                double SecondNumber = Numbers >> 0;
                double FirstNumber = Numbers >> 0;
                Numbers << Calculate(FirstNumber, SecondNumber, Operations >> 0);
            }
            Operations << MathEquation[i];
        }else {
            if (MathEquation[i] == '('){
                if (MathEquation[i+1] == '-'){
                    ++i;
                    while (MathEquation[i] != ')'){
                        Expression = "";
                        Expression += MathEquation[i];
                        ++i;
                    }
                    Numbers.push(-1* stod(Expression));
                } else{
                    Operations << MathEquation[i];
                }
            }
            else if(MathEquation[i] == ')'){
                while (Operations.top() != '('){
                    double SecondNumber = Numbers >> 0;
                    double FirstNumber = Numbers >> 0;
                    Numbers << Calculate(FirstNumber, SecondNumber, Operations >> 0);
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
                Numbers.push(stod(Expression));
            }
        }

    }
    while (!Operations.isEmpty()){
        double S_Number = Numbers >> 0;
        double F_Number = Numbers >> 0;
        Numbers << Calculate(F_Number, S_Number, Operations >> 0);
    }
    return Numbers.top();
}
void Solution()
{
    string MathEquation;
    cout << "Enter your expression:" << endl;
    getline(cin, MathEquation);
    cout << "It is equal to:" << endl;
    cout << CalculateEquation(MathEquation) << endl;
}