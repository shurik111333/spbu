// ProjectB.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

int main()
{
	ifstream fin("money.in");
	ofstream fout("money.out");
	int n = 0;
	fin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
	}
	int k = 0;
	fin >> k;
	int dp[10000] = {};
	dp[0] = 1;
	int *b = new int[k];
	for (int i = 0; i < k; i++)
	{
		fin >> b[i];
		for (int j = 1; j <= b[i]; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (j - a[k] >= 0)
				{
					if (dp[j - a[k]] == 1)
					{
						dp[j] = 1;
						break;
					}
				}
			}
		}
		fout << dp[b[i]] << " ";
	}

	return 0;
}

