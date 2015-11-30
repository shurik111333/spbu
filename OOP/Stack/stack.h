#pragma once

template <typename T>
class Stack
{
public:
    Stack()
    {
        this->top = nullptr;
    }
    ~Stack()
    {
        while (this->top)
        {
            this->pop();
        }
    }
    void push(T value)
    {
        StackElement *newElement = StackElement(value, this->top);
        this->top = newElement;
    }
    T pop()
    {

        StackElement *elementForDelete = this->top;
        this->top = this->top->getNext();
        int result = elementForDelete->getValue();
        delete elementForDelete;
        return result;
    }
    T top() const
    {
        return this->top->getValue();
    }


private:
    class StackElement
    {
    public:
        StackElement(T value, StackElement *next)
        {
            this->value = value;
            this->next = next;
        }
        T getValue() const
        {
            return this->value;
        }
        StackElement *getNext() const
        {
            return this->next;
        }
    private:
        T value;
        StackElement *next;
    };
    StackElement *Top;
};
