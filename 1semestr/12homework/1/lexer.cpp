#include "lexer.h"
#include <cstring>

//bool Lexer::isFinishState = {false, false, true, false, true, false, false, true};

//const bool isFinishState[] = {false, false, true, false, true, false, false, true};

/*enum State
{
    startState,
    numberSignState,
    integerState,
    pointState,
    decimalState,
    exponentSymbolState,
    exponentSignState,
    exponentState
};*/

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

void Lexer::init()
{
    index = 0;
}

bool Lexer::isNumber()
{
    return true;
}

Lexer::Token Lexer::next()
{
    skipSpaces();
    if (index >= length)
        return empty;
    if (isNumber())
        return Lexer::number;
    switch(this->string[index++])
    {
    case '+':
        return plus;
    case '-':
        return minus;
    case '*':
        return multiply;
    case '/':
        return divide;
    default:
    {
        index--;
        return error;
    }
    }
}
