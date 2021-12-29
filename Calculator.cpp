#include "Calculator.h"


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

double Calculate(double F_Number, double S_Number, char Operation) {
    if (Operation == '*') {
        return (F_Number * S_Number);
    }
    if (Operation == '-') {
        return (F_Number - S_Number);
    }
    if (Operation == '+') {
        return (F_Number + S_Number);
    }
    if (Operation == '^') {
        return (pow(F_Number, S_Number));
    }
    if (Operation == '/') {
        if (S_Number == 0) {
            throw runtime_error("Can't divide by zero");
        }
        return (F_Number / S_Number);
    }
    return 0;
}

string ExactEquation(string MathEquation){
    char ExactSymbols[12] = {'1','2','3','4','5','6','7','8','9','0',' ','.'};
    for(int i = 0; i < 12 ; i++){
        for(int j = 0 ; j < MethEquation.size() ; j++){
            if(MathEquation[j] != ExactSymbols[i]){
                 throw runtime_error("Enter numbers not letters");
            } 
            else{
                return MathEquation;
            } 
        }
    }
}

string DeleteSpacesInEquation(string MathEquation) {
    string WithoutSpaces = {};
    for (int i = 0; i < MathEquation.size(); ++i) {
        if (MathEquation[i] != ' ') {
            WithoutSpaces += MathEquation[i];
        }
    }
    if(WithoutSpaces.empty()){
        throw runtime_error("Enter numbers");
    } 
    return WithoutSpaces;
}

int OpenBracket(string MathEquation) {
    int Num_Open = 0;
    for (int i = 0; i < MathEquation.size(); ++i) {
        if (MathEquation[i] == '(') {
            ++Num_Open;
        }
    }
    return Num_Open;
}

int CloseBracket(string MathEquation) {
    int Num_Close = 0;
    for (int i = 0; i < MathEquation.size(); ++i) {
        if (MathEquation[i] == '(') {
            ++Num_Close;
        }
    }
    return Num_Close;
}

void CheckForClosedBrackets(string &MathEquation) {
    if (OpenBracket(MathEquation) != CloseBracket(MathEquation)) {
        throw runtime_error("All brackets should be closed");
    }
}

int NumOfOperations(string MathEquation) {
    int Operation_Num = 0;
    for (int i = 0; i < MathEquation.size(); ++i) {
        if (Operation(MathEquation[i]) &&
            (i != MathEquation.size() - 1) &&
            MathEquation[i] != '('
            && MathEquation[i - 1] != '('
            && MathEquation[i] != ')') {
            ++Operation_Num;
        }
    }
    return Operation_Num;
}


double Polish(string MathEquation) {
    string Temp_str{};
    Temp_str = DeleteSpacesInEquation(MathEquation);
    MathEquation = Temp_str;

    CheckForClosedBrackets(MathEquation);

    if (NumOfOperations(MathEquation) == 0 && OpenBracket(MathEquation) == 0) {
        return stod(MathEquation);
    } else if (NumOfOperations(MathEquation) == 0) {
        Temp_str = "";
        for (int i = 0; i < MathEquation.size(); ++i) {
            if (MathEquation[i] != '(' && MathEquation[i] != ')') {
                Temp_str += MathEquation[i];
            }
        }
        return stod(Temp_str);
    }

    Stack<char> Symbols;
    Stack<double> Numbers;

    for (int j = 0; j < MathEquation.size(); ++j) {
        if (Operation(MathEquation[j])) {
            if (j == 0 && MathEquation[j + 1] == '-') {
                if (MathEquation[j] == '(') {
                    string ForBrackets = "0";
                    ForBrackets += Temp_str;
                    return Polish(ForBrackets);
                } else {
                    while (!Operation(MathEquation[j])) {
                        Temp_str += MathEquation[j++];
                    }
                    Numbers.push(stod(Temp_str));
                }
            }
            while (!(Symbols.isEmpty()) && OperationPriority(MathEquation[j]) <= OperationPriority(Symbols.top())) {
                double S_Number = Numbers.pop();
                double F_Number = Numbers.pop();
                Numbers.push(Calculate(F_Number, S_Number, Symbols.pop()));
            }
            Symbols.push(MathEquation[j]);
            if (MathEquation[j + 1] == '-') {
                if (MathEquation[j + 2] == '(') {
                    ++j;
                    Temp_str = "";
                    while (MathEquation[j] != ')') {
                        Temp_str += MathEquation[++j];
                    }
                    Numbers.push(-Polish(Temp_str));
                } else {
                    Temp_str = " ";
                    j++;
                    while ((!Operation(MathEquation[j]) || MathEquation[j] == '-') && j != MathEquation.size()) {
                        Temp_str += MathEquation[j++];
                    }
                    j--;
                    Numbers.push(stod(Temp_str));
                }
            }
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
    cout << Polish(MathEquation) << endl;
}
