#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    string MathEquation;
    cin >> MathEquation;
    cout << "\nAnswer: " << CalculateEquation(MathEquation);
    return 0;
}
