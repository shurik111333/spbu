#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    String str1 = String("hello, ");
    cout << "Строка 1: \"" << str1 << "\"" << endl;
    cout << "Длина строки \"" << str1 << "\" = " << str1.length() << endl;
    String strClone = str1.clone();
    cout << "Клонированная строка: \"" << strClone << "\"" << endl;
    cout << "Исходная строка ";
    if (str1 != strClone)
        cout << "не ";
    cout << "равна клонированной" << endl;
    String str2 = String("world!");
    cout << "Строка 2: \"" << str2 << "\"" << endl;
    cout << "Строка 1 ";
    if (str1 < str2)
        cout << "меньше";
    else
        cout << "больше";
    cout << " строки 2" << endl;
    cout << "Строка 2 ";
    if (str2 < str1)
        cout << "меньше";
    else
        cout << "больше";
    cout << " строки 1" << endl;
    //concat(str1, str2);
    //cout << "Конкатенация первых двух строк: \"" << *str1 << "\"" << endl;
    int substrLength = 9;
    int startIndex = 0;
    cout << str1[0] << endl;
    String str3 = str1.substr(startIndex, substrLength);
    cout << "Подстрока с " << startIndex << " индекса длины " << str3.length() << ": \"" << str3 << "\"" << endl;
    cout << "Конвертирование строки 1 в char *: \"" << str1.toChar() << "\"" << endl;
    String str4 = String("");
    cout << "Строка 4: \"" << str4 << "\"" << endl;
    cout << "Строка 4 ";
    if (!str4.empty())
        cout << "не";
    cout << "пустая" << endl;
    return 0;
}

