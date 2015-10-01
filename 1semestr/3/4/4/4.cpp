// 4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include "infixToPostfix.h"
#include "calculatePostfix.h"

using namespace std;

const int maxLen = 255;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "��������� ������� �������� ���������" << endl;
	cout << "������� ���������" << endl;
	char *inputString = new char[maxLen];
	memset(inputString, '\0', maxLen * sizeof(char));
	fgets(inputString, maxLen, stdin);
	int length = 0;
	while (inputString[length] != '\0')
	{
		length++;
	}
	printf("%g\n", calculatePostfix(infixToPostfix(inputString, length)));
	return 0;
}

