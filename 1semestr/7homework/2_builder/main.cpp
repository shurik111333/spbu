#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    String str1 = String("hello, ");
    cout << "������ 1: \"" << str1 << "\"" << endl;
    cout << "����� ������ \"" << str1 << "\" = " << str1.length() << endl;
    String strClone = str1.clone();
    cout << "������������� ������: \"" << strClone << "\"" << endl;
    cout << "�������� ������ ";
    if (str1 != strClone)
        cout << "�� ";
    cout << "����� �������������" << endl;
    String str2 = String("world!");
    cout << "������ 2: \"" << str2 << "\"" << endl;
    cout << "������ 1 ";
    if (str1 < str2)
        cout << "������";
    else
        cout << "������";
    cout << " ������ 2" << endl;
    cout << "������ 2 ";
    if (str2 < str1)
        cout << "������";
    else
        cout << "������";
    cout << " ������ 1" << endl;
    //concat(str1, str2);
    //cout << "������������ ������ ���� �����: \"" << *str1 << "\"" << endl;
    int substrLength = 9;
    int startIndex = 0;
    cout << str1[0] << endl;
    String str3 = str1.substr(startIndex, substrLength);
    cout << "��������� � " << startIndex << " ������� ����� " << str3.length() << ": \"" << str3 << "\"" << endl;
    cout << "��������������� ������ 1 � char *: \"" << str1.toChar() << "\"" << endl;
    String str4 = String("");
    cout << "������ 4: \"" << str4 << "\"" << endl;
    cout << "������ 4 ";
    if (!str4.empty())
        cout << "��";
    cout << "������" << endl;
    return 0;
}
