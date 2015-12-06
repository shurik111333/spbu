#include <iostream>
#include <calculator.h>

using namespace std;

int main()
{
    Calculator calc;
    calc.push(2);
    calc.push(2);
    calc.push(3);
    calc.add();
    calc.multiply();
    cout << calc.result();
    return 0;
}

