// 3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <cstring>
#include "calculatePostfix.h"

using namespace std;

const int maxLen = 255;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "��������� ������� �������� ��������� � ����������� ������" << endl;
	cout << "������� ��������� ��� ��������" << endl;
	char *inputString = new char[maxLen];
	memset(inputString, '\0', maxLen * sizeof(char));
	scanf("%s", inputString);
	printf("�����: %g\n", calculatePostfix(inputString));
	return 0;
}
