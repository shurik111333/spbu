// ProjectD.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

long long max(long long a, long long b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	ifstream fin("knapsack.in");
	ofstream fout("knapsack.out");
	int n = 0, s = 0;
	fin >> s >> n;
	int v[500] = {};
	for (int i = 1; i <= n; i++)
	{
		fin >> v[i];
	}
	long long res[500][11001] = {};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			if (j < v[i])
			{
				res[i][j] = res[i - 1][j];
			}
			else
			{
				res[i][j] = max(res[i - 1][j - v[i]] + v[i], res[i - 1][j]);
			}
		}
	}
	fout << res[n][s];
	return 0;
}

