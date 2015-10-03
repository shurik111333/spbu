// ProjectC.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>
#include <limits.h>

using namespace std;

long long abs(long long a)
{
	if (a < 0)
		return -a;
	return a;
}

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
	ifstream fin("nails.in");
	ofstream fout("nails.out");
	int n = 0;
	fin >> n;
	int a[500] = {}, p[500] = {}, d[500] = {};
	for (int i = 1; i <= n; i++)
	{
		fin >> a[i];
	}
	qSort(1, n, a);
	d[1] = a[2] - a[1];
	p[1] = 1;
	p[2] = 1;
	a[n + 1] = INT_MAX / 2;
	for (int i = 2; i <= n; i++)
	{

	}
	return 0;
}

