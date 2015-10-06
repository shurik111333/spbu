#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

long long Pow(int a, int b)
{
	if (b == 0)
		return 1;
	else
	{
		if ((b & 1) == 0)
		{
			long long t = Pow(a, b / 2);
			return t * t;
		}
		else
			return a * Pow(a, b - 1);
	}
}

void qSort(int left, int right, string arr[])
{
	int leftIndex = left;
	int rightIndex = right;
	string comparingElement = arr[(left + right) / 2];
	while (leftIndex < rightIndex)
	{
		//while (arr[leftIndex] < comparingElement)
		while (arr[leftIndex].compare(comparingElement) < 0)
		{
			leftIndex++;
		}
		//while (arr[rightIndex] > comparingElement)
		while (arr[rightIndex].compare(comparingElement) > 0)
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

int search(int left, int right, string x, string s[])
{
	int l = left;
	int r = right;
	int middle = 0;
	while (r - l > 1)
	{
		middle = (l + r) / 2;
		if (s[middle].compare(x) < 0)
		{
			l = middle + 1;
		}
		else
			r = middle;
	}
	if (s[l].compare(x) == 0)
		return l;
	else
		return r;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	int amount = Pow(2, n);
	int el = amount * 2 - 1;
	//char **p = new *char[amount * 2];
	string s[600000] = {};
	string s1[500000] = {};
	string p;
	for (int i = el; i >= amount; i--)
	{
		fin >> s[i];
		s1[el - i + 1] = s[i];
	}
	qSort(1, amount, s1);
	char c;
	for (int i = amount - 1; i > 0; i--)
	{
		fin >> c;
		if (c == 'W')
			s[i] = s[2 * i + 1];
		else 
			s[i] = s[2 * i];
	}

	int q;
	fin >> q;
	string t1 = {}, t2 = {};
	for (int i = 0; i < q; i++)
	{
		fin >> t1 >> t2;
		int w = el - search(1, amount, t1, s1) + 1;
		//while (s[w] != t1) w++;
		bool flag = false;
		while (w != 1)
		{
			if (s[w / 2] == t2)
			{
				flag = true;
				break;
			}
			w = w / 2;
		}
		if (flag)
		{
			fout << "Lose" << endl;
			continue;
		}
		w = el - search(1, amount, t2, s1) + 1;
		//while (s[w] != t2) w++;
		flag = false;
		while (w != 1)
		{
			if (s[w / 2] == t1)
			{
				flag = true;
				break;
			}
			w = w / 2;
		}
		if (flag)
		{
			fout << "Win" << endl;
			continue;
		}
		fout << "Unknown" << endl;

	}

   return 0;
}