/*#include <stack.h>

Stack::Stack()
{
    this->top = nullptr;
}

Stack::~Stack()
{
    while (this->top)
    {
        this->pop();
    }
}

void Stack::push(int value)
{
    StackElement *newElement = StackElement(value, this->top);
    this->top = newElement;
}

int Stack::pop()
{

    StackElement *elementForDelete = this->top;
    this->top = this->top->getNext();
    int result = elementForDelete->getValue();
    delete elementForDelete;
    return result;
}

int Stack::top() const
{
    return this->top->getValue();
}

Stack::StackElement::StackElement(int value, StackElement *next)
{
    this->value = value;
    this->next = next;
}

int Stack::StackElement::getValue() const
{
    return this->value;
}

Stack::StackElement *Stack::STackElement::getNex() const
{
    return this->next;
}*/
