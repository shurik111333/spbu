#pragma once

#include <stack.h>

class Calculator
{
private:
    Stack<int> *stack;
public:
    Calculator();
    ~Calculator();
    void add();
    void subtract();
    void multiply();
    void divide();
    void push(int value);
    int result() const;
};
