#ifndef LAB_8_CALCULATOR_H
#define LAB_8_CALCULATOR_H

#include "Stack.h"
#include "cmath"

using namespace std;

bool Operation(char OperationType);

int OperationPriority(char OperationType);

double Calculate(double F_Number, double S_Number, char Operation);

int OpenBracket(string MathEquation);

int CloseBracket(string MathEquation);

void CheckForClosedBrackets(string &Equation);

double Polish(string MathEquation);

void Solution();


#endif //LAB_8_CALCULATOR_H
