#include <iostream>
#include "lexer.h"

using namespace std;

int main()
{
    Lexer l = Lexer("-2 +3.4- 1E01*2.3f");
    Lexer::Token t;
    return 0;
}

