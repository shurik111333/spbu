// 3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <cstring>
#include "calculatePostfix.h"

using namespace std;

const int maxLen = 255;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Программа считает значение выражения в постфиксной записи" << endl;
	cout << "Введите выражение без пробелов" << endl;
	char *inputString = new char[maxLen];
	memset(inputString, '\0', maxLen * sizeof(char));
	scanf("%s", inputString);
	printf("Ответ: %g\n", calculatePostfix(inputString));
	return 0;
}

