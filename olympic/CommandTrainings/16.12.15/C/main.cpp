#include <iostream>
#include <fstream>

using namespace std;

int ansLast[10] = {};
int ansFirst[10] = {};

long long m = 100000000000000000;

int main()
{
	ifstream fin("digit-statistics.in");
	ofstream fout("digit-statistics.out");
	int n, a;
	fin >> n >> a;
	ansLast[a] = 1;
	int count = 1;
	int q = a;
	for (int i = 1; i < n; i++)
	{
		q = (q * a) % 10;
		if (ansLast[q] > 0)
			break;
		count++;
		ansLast[q] = 1;
	}
	q = 1;
	int k = n / count;
	for (int i = 0; i < 10; i++)
	{
		ansLast *= k;
	}
	int c = n % count;
	for (int i = 0; i < c; i++)
	{
		q = (q * a) % 10;
		ansLast[q]++;
	}
	long long f	= 1;
	for (int i = 0; i < n; i++)
	{
		f *= a;
		if (f < m)
			f -= m;
		
	}
	return 0;
}

