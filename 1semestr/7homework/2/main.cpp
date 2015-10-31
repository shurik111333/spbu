#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char *charStr = "hello, ";
    String *str1 = getNewString(charStr);
    int len = length(str1);
    String *strClone = clone(str1);
    int cmp = compare(str1, strClone);
    char *charStr2 = "world!";
    String *str2 = getNewString(charStr2);
    cmp = compare(str1, str2);
    cmp = compare(str2, str1);
    concat(str1, str2);
    String *str3 = substring(str1, 0, 7);
    char *charStr3 = stringToChar(str1);
    deleteString(str1);
    deleteString(str2);
    deleteString(str3);
    return 0;
}

