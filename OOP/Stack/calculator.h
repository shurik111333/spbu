#pragma once

#include "stack.h"
#include "istack.h"

class Calculator
{
private:
    IStack<int> &stack;
public:
    //Calculator();
    Calculator(IStack<int> &stack);
    ~Calculator();
    void add();
    void subtract();
    void multiply();
    void divide();
    void push(int value);
    int result() const;
};
