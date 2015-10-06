// ProjectE.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

int main()
{
	ifstream fin("network.in");
	ofstream fout("network.out");
	int n = 0;
	fin >> n;
	//int **a = new int *[n + 1];
	char a[20][20] = {};
	for (int i = 1; i <= n; i++)
	{
		//a[i] = new int[n + 1];
		for (int j = 1; j <= n; j++)
		{
			fin >> a[i][j];
		}
	}
	long long mask = (1 << n) - 1;
	//int *d = new int[mask + 1];
	int d[300000] = {};
	d[0] = 1;
	int x = 0;
	for (int i = 0; i <= mask; i++)
	{
		if (d[i] == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (a[j][k] == 'Y' && ((i & (1 << (j - 1))) == 0) && ((i & (1 << (k - 1))) == 0))
					{
						x = i | (1 << (j - 1));
						x = x | (1 << (k - 1));
						d[x] = 1;
					}
				}
			}
		}
	}
	int res = 0;
	int currRes = 0;
	int currMask = 0;
	for (int i = 1; i <= mask; i++)
	{
		if (d[i] == 1)
		{
			currRes = 0;
			currMask = i;
			while (currMask > 0)
			{
				currRes += currMask & 1;
				currMask = currMask >> 1;
			}
			if (currRes > res)
				res = currRes;
		}
	}
	fout << res;
	return 0;
}