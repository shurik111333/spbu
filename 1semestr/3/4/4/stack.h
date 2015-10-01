#pragma once

struct Stack;

Stack *getNewStack();

double getTop(Stack *stack);

double pop(Stack *stack);

void push(Stack *stack, double newValue);

void clear(Stack *stack);

bool isEmpty(Stack *stack);