#include <iostream>
#include <calculator.h>
#include "stack.h"
#include "istack.h"

using namespace std;

int main()
{
    Stack<int> stack;
    Calculator calc(stack);
    calc.push(2);
    calc.push(2);
    calc.push(3);
    calc.add();
    calc.multiply();
    cout << calc.result();
    return 0;
}

