// ProjectC.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <stdio.h>

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

/*int search(int l, int r, int x, int arr[])
{
	int left = l;
	int right = r;
	int middle = 0;
	while (right - left > 1)
	{
		middle = (right + left) / 2;
		if (arr[middle] < x)
			right = middle - 1;
		else
			if (arr[middle] == x)
				right = middle;
			else
				left = middle + 1;
	}
	if (arr[left] == x)
		return left;
	else
		return right;
}*/

int main()
{
	int n = 0;
	cin >> n;
	int res[1000] = {}, val[300000] = {};
	for (int i = 1; i <= n * n; i++)
	{
		cin >> val[i];
	}
	qSort(1, n * n, val);
	int count = 0;
	int currIndex = n * n;
	while (true)
	{
		res[count] = val[currIndex];
		count++;
		if (count == n)
			break;
		currIndex--;
		if (val[currIndex] == val[currIndex + 1])
		{
			for (int i = count - 1; i >= 0; i++)
			{
				if (res[i] == val[currIndex])
				{
					currIndex -= 2;
				}
				else
					break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", res[i]);
	}
	return 0;
}

