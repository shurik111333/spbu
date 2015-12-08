#pragma once

class Lexer
{
private:
    int length;
    char *string;
    int index;

    const bool isFinishState[8] = {false, false, true, false, true, false, false, true};
    const char point = '.', exp = 'E';

    static bool isSpace(const char symbol);

    static bool isSign(const char symbol);

    void skipSpaces();

    bool isNumber();

public:

    enum Token
    {
        empty,
        number,
        plus = '+',
        minus = '-',
        multiply = '*',
        divide = '/',
        error
    };

    Lexer();

    Lexer(const char *string);

    void init();

    Token next();
};
