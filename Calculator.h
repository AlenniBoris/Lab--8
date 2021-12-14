#ifndef LAB_8_CALCULATOR_H
#define LAB_8_CALCULATOR_H

#include "Stack.h"
#include "cmath"

using namespace std;


double Calculate(double FirstNumber, double SecondNumber, char Operation);
bool Operation(char OperationType);
int OperationPriority(char OperationType);
double CalculateEquation(string MathEquation);


#endif //LAB_8_CALCULATOR_H
