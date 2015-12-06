// ProjectF.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

long long max(long long a, long long b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	ifstream fin("lcs.in");
	ofstream fout("lcs.out");
	int n = 0, m = 0;
	fin >> n;
	int *a = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		fin >> a[i];
	}
	fin >> m;
	int *b = new int[m + 1];
	for (int i = 1; i <= m; i++)
	{
		fin >> b[i];
	}
	int res[1100][1100] = {};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				res[i][j] = res[i - 1][j - 1] + 1;
			}
			res[i][j] = max(res[i - 1][j], max(res[i][j], res[i][j - 1]));
		}
	}
	fout << res[n][m];
	return 0;
}

