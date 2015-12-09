#include "calculator.h"
#include "istack.h"

Calculator::Calculator(IStack<int> &stack)
    :stack(stack)
{}

Calculator::~Calculator()
{
    //delete stack;
}

void Calculator::add()
{
    stack.push(stack.pop() + stack.pop());
}

void Calculator::subtract()
{
    int num1 = stack.pop();
    int num2 = stack.pop();
    stack.push(num2 - num1);
}

void Calculator::multiply()
{
    stack.push(stack.pop() * stack.pop());
}

void Calculator::divide()
{
    int num1 = stack.pop();
    int num2 = stack.pop();
    stack.push(num2 / num1);
}

void Calculator::push(int value)
{
    stack.push(value);
}

int Calculator::result() const
{
    return stack.getTop();
}
