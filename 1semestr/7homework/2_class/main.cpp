#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    char *charStr = "hello, ";
    String str1 = charStr;
    cout << "������ 1: \"" << str1 << "\"" << endl;
    cout << "����� ������ \"" << str1 << "\" = " << str1.length() << endl;
    String strClone = str1;
    cout << "������������� ������: \"" << strClone << "\"" << endl;
    //int cmp = String::compare(str1, strClone);
    cout << "�������� ������ ";
    if (str1 != strClone)
        cout << "�� ";
    cout << "����� �������������" << endl;
    char *charStr2 = "world!";
    String str2 = charStr2;
    cout << "������ 2: \"" << str2 << "\"" << endl;
    //cmp = String::compare(str1, str2);
    cout << "������ 1 ";
    //str1->length = 5;
    if (str1 < str2)
        cout << "������";
    else
        cout << "������";
    cout << " ������ 2" << endl;

    //cmp = String::compare(str2, str1);
    cout << "������ 2 ";
    if (str2 < str1)
        cout << "������";
    else
        cout << "������";
    cout << " ������ 1" << endl;
    str1.append(str2);
    cout << "������������ ������ ���� �����: \"" << str1 << "\"" << endl;
    int substrLength = 9;
    int startIndex = 0;
    String str3 = str1.substring(startIndex, substrLength);
    cout << "��������� � " << startIndex << " ������� ����� " << str3.length() << ": \"" << str3 << "\"" << endl;
    String str4 = "";
    cout << "������ 4: \"" << str4 << "\"" << endl;
    cout << "������ 4 ";
    if (!str4.isEmpty())
        cout << "�� ";
    cout << "������" << endl;
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
