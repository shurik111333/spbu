#pragma once

#include <stack.h>

class Calculator
{
private:
    Stack *stack;
public:
    Calculator();
    ~Calculator();
    void add();
    void subtract();
    coid multiply();
    void divide();
    void push(int value);
    int result() const;
};