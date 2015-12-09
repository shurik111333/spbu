#pragma once

#include "istack.h"

template <typename T>
class Stack : public IStack<T>
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
        StackElement *newElement = new StackElement(value, this->top);
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
    T getTop() const
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
    StackElement *top;
};

template <typename T>
class StackArray : public IStack<T>
{
private:
    T *array;
    int size;
    int top;

    const static int defaultSize = 10;

    void increaseStack()
    {
        int newSize = size * 2;
        T *newArray = new T[newSize];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        size = newSize;
        delete[] array;
        array = newArray;
    }

public:

    StackArray(int size = defaultSize)
    {
        this->size = size;
        this->array = new T[this->size];
        this->top = 0;
    }

    ~StackArray()
    {
        delete[] array;
    }

    void push(T value)
    {
        if (top >= size)
            increaseStack();
        array[top++] = value;
    }

    T pop()
    {
        return array[--top];
    }

    T getTop() const
    {
        return array[top - 1];
    }
};
