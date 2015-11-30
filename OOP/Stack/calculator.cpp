#include <calculator.h>

Calculator::Calculator()
{
    stack = new Stack();
}

Calculator::~Calculator()
{
    delete stack;
}

void Calculator::add()
{
    stack->push(stack->pop() + stack->pop());
}

void Calculator::substract()
{
    stack->push(stack->pop() - stack->pop());
}

void Calculator::multiply()
{
    stack->push(stack->pop() * stack->pop());
}

void Calculator::divide()
{
    stack->push(stack->pop() / stack->pop());
}

void Calculator::push(int value)
{
    stack->push(value);
}

int Calculator::result() const
{
    return stack->top();
}