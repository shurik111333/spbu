#pragma once

struct Stack;

Stack *getNewStack();

char getTop(Stack *stack);

char pop(Stack *stack);

void push(Stack *stack, char newValue);

void clear(Stack *stack);

bool isEmpty(Stack *stack);