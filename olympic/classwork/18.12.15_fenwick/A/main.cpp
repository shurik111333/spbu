#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

long long *t;
long long *a;
int n, k;

void update(int pos, int x)
{
	for (int i = pos; i < n; i = (i + 1) | i)
	{
		t[i] += x - a[pos];
	}
	a[pos] = x;
}

long long sum(int l, int r)
{
	long long result = 0;
	for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
	{
		result += t[i];
	}
	for (int i = l - 1; i >= 0; i = (i & (i + 1)) - 1)
	{
		result -= t[i];
	}
	return result;
}

int main()
{
	ifstream fin("sum.in");
	ofstream fout("sum.out");
	fin >> n >> k;
	t = new long long[n];
	a = new long long[n];
	for (int i = 0; i < n; i++)
	{
		t[i] = 0;
		a[i] = 0;
	}
	for (int i = 0; i < k; i++)
	{
		char c;
		int a, b;
		fin >> c >> a >> b;
		if (c == 'A')
		{
			update(a - 1, b);
		}
		else
			fout << sum(a - 1, b - 1) << endl;
	}
	return 0;
}

