// Project11.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>
#include <limits.h>
#include <ctime>

using namespace std;

void qSort(int left, int right, int arr[])
{
	int leftIndex = left;
	int rightIndex = right;
	int comparingElement = arr[(left + right) / 2];
	while (leftIndex < rightIndex)
	{
		while (arr[leftIndex] < comparingElement)
		{
			leftIndex++;
		}
		while (arr[rightIndex] > comparingElement)
		{
			rightIndex--;
		}
		if (leftIndex <= rightIndex)
		{
			swap(arr[leftIndex], arr[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	}
	if (leftIndex < right)
	{
		qSort(leftIndex, right, arr);
	}
	if (rightIndex > left)
	{
		qSort(left, rightIndex, arr);
	}
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, s;
	int p[110000] = {};
	fin >> n >> s;
	for (int i = 0; i <= n; i++)
	{
		p[i] = INT_MAX / 2;
	}
	int a = 0, b = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b;
		if (p[a] > b)
		{
			p[a] = b;
		}
	}
	qSort(1, n, p);
	int result = 0;
	int sum = 0;
	while (result < n && (sum + p[result + 1]) <= s)
	{
		result++;
		sum += p[result];
	}
	fout << result;
	return 0;
}