#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    char *charStr = "hello, ";
    String str1 = charStr;
    cout << "Строка 1: \"" << str1 << "\"" << endl;
    cout << "Длина строки \"" << str1 << "\" = " << str1.length() << endl;
    String strClone = str1;
    cout << "Клонированная строка: \"" << strClone << "\"" << endl;
    //int cmp = String::compare(str1, strClone);
    cout << "Исходная строка ";
    if (str1 != strClone)
        cout << "не ";
    cout << "равна клонированной" << endl;
    char *charStr2 = "world!";
    String str2 = charStr2;
    cout << "Строка 2: \"" << str2 << "\"" << endl;
    //cmp = String::compare(str1, str2);
    cout << "Строка 1 ";
    //str1->length = 5;
    if (str1 < str2)
        cout << "меньше";
    else
        cout << "больше";
    cout << " строки 2" << endl;

    //cmp = String::compare(str2, str1);
    cout << "Строка 2 ";
    if (str2 < str1)
        cout << "меньше";
    else
        cout << "больше";
    cout << " строки 1" << endl;
    str1.append(str2);
    cout << "Конкатенация первых двух строк: \"" << str1 << "\"" << endl;
    int substrLength = 9;
    int startIndex = 0;
    String str3 = str1.substring(startIndex, substrLength);
    cout << "Подстрока с " << startIndex << " индекса длины " << str3.length() << ": \"" << str3 << "\"" << endl;
    String str4 = "";
    cout << "Строка 4: \"" << str4 << "\"" << endl;
    cout << "Строка 4 ";
    if (!str4.isEmpty())
        cout << "не ";
    cout << "пустая" << endl;
    /*String::deleteString(str1);
    String::deleteString(str2);
    String::deleteString(str3);*/
    delete &str1;
    delete &str2;
    delete &str3;
    delete &str4;
    delete &strClone;
    return 0;
}

