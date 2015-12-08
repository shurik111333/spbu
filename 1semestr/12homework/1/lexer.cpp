#include "lexer.h"
#include <cstring>
#include <cctype>

//private----------------------------------------//

enum State
{
    startState,
    integerState,
    pointState,
    decimalState,
    exponentSymbolState,
    exponentSignState,
    exponentState
};

bool Lexer::isSpace(const char symbol)
{
    return (symbol == ' ' || symbol == '\t' || symbol == '\n');
}

void Lexer::skipSpaces()
{
    while (isSpace(this->string[index]))
    {
        index++;
    }
}

bool Lexer::isSign(const char symbol)
{
    return (symbol =='+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool Lexer::isNumber()
{
    bool isInNumber = true;
    int newIndex = index - 1;
    State state = startState;
    while (isInNumber)
    {
        char c = this->string[++newIndex];
        switch (state)
        {
        case startState:
        {
            if (isdigit(c))
            {
                state = integerState;
                break;
            }
            isInNumber = false;
            break;
        }
        case integerState:
        {
            if (isdigit(c))
                break;
            if (c == point)
            {
                state = pointState;
                break;
            }
            if (c == exp)
            {
                state = exponentSymbolState;
                break;
            }
            isInNumber = false;
            break;
        }
        case pointState:
        {
            if (isdigit(c))
                state = decimalState;
            else
                isInNumber = false;
            break;
        }
        case decimalState:
        {
            if (isdigit(c))
                break;
            if (c == exp)
            {
                state = exponentSymbolState;
                break;
            }
            isInNumber = false;
            break;
        }
        case exponentSymbolState:
        {
            if (c == '+' || c == '-')
            {
                state = exponentSignState;
                break;
            }
            if (isdigit(c))
            {
                state = exponentState;
                break;
            }
            isInNumber = false;
            break;
        }
        case exponentSignState:
        {
            if (isdigit(c))
                state = exponentState;
            else
                isInNumber = false;
            break;
        }
        case exponentState:
        {
            if (!isdigit(c))
                isInNumber = false;
            break;
        }
        }
    }
    if (isFinishState[state])
        index = newIndex;
    return isFinishState[state];
}

//public-----------------------------------------//

Lexer::Lexer()
    :length(0), string(nullptr), index(0)
{}

Lexer::Lexer(const char *string)
{
    length = strlen(string);
    this->string = new char[length + 1];
    strcpy(this->string, string);
    this->string[length] = '\0';
    index = 0;
}

void Lexer::init()
{
    index = 0;
}

Lexer::Token Lexer::next()
{
    skipSpaces();
    if (index >= length)
        return empty;
    if (isNumber())
        return Lexer::number;
    if (isSign(this->string[index++]))
        return (Token)this->string[index - 1];
    else
        return Lexer::error;
}
