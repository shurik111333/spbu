#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("stars.in");
	ofstream fout("stars.out");
	int n = 0;
	fin >> n;
	long long ***t = new long long**[n];
	long long ***a = new long long**[n];
	for (int i = 0; i < n; i++)
	{
		t[i] = new long long*[n];
		a[i] = new long long*[n];
		for (int j = 0; j < n; j++)
		{
			t[i][j] = new long long[n];
			a[i][j] = new long long[n];
			for (int k = 0; k < n; k++)
			{
				t[i][j][k] = 0;
				a[i][j][k] = 0;
			}
		}
	}
	int m = 0;
	while (true)
	{
		fin >> m;
		if (m == 3)
			break;
		if (m == 1)
		{
			int x, y, z, k1;
			fin >> x >> y >> z >> k1;
			if ((-k1) > a[x][y][z])
				k1 = -a[x][y][z];
			for (int i = x; i < n; i = (i + 1) | i)
			{
				for (int j = y; j < n; j = (j + 1) | j)
				{
					for (int k = z; k < n; k = (k + 1) | k)
					{
						t[i][j][k] += k1;
					}
				}
			}
			a[x][y][z] += k1;
		}
		if (m == 2)
		{
			int x1, y1, z1, x2, y2, z2;
			fin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			long long sum = 0;
			for (int i = x2; i >= 0; i = ((i + 1) & i) - 1)
			{
				for (int j = y2; j >= 0; j = ((j + 1) & j) - 1)
				{
					for (int k = z2; k >= 0; k = ((k + 1) & k) - 1)
					{
						sum += t[i][j][k];
					}
				}
			}
			for (int i = x1 - 1; i >= 0; i = ((i + 1) & i) - 1)
			{
				for (int j = y2; j >= 0; j = ((j + 1) & j) - 1)
				{
					for (int k = z2; k >= 0; k = ((k + 1) & k) - 1)
					{
						sum -= t[i][j][k];
					}
				}
			}
			
			for (int i = x2; i >= 0; i = ((i + 1) & i) - 1)
			{
				for (int j = y1 - 1; j >= 0; j = ((j + 1) & j) - 1)
				{
					for (int k = z2; k >= 0; k = ((k + 1) & k) - 1)
					{
						sum -= t[i][j][k];
					}
				}
			}
			
			for (int i = x2; i >= 0; i = ((i + 1) & i) - 1)
			{
				for (int j = y2; j >= 0; j = ((j + 1) & j) - 1)
				{
					for (int k = z1 - 1; k >= 0; k = ((k + 1) & k) - 1)
					{
						sum -= t[i][j][k];
					}
				}
			}
			
			for (int i = x1 - 1; i >= 0; i = ((i + 1) & i) - 1)
			{
				for (int j = y1 - 1; j >= 0; j = ((j + 1) & j) - 1)
				{
					for (int k = z2; k >= 0; k = ((k + 1) & k) - 1)
					{
						sum += t[i][j][k];
					}
				}
			}
			
			for (int i = x1 - 1; i >= 0; i = ((i + 1) & i) - 1)
			{
				for (int j = y2; j >= 0; j = ((j + 1) & j) - 1)
				{
					for (int k = z1 - 1; k >= 0; k = ((k + 1) & k) - 1)
					{
						sum += t[i][j][k];
					}
				}
			}
			
			for (int i = x2; i >= 0; i = ((i + 1) & i) - 1)
			{
				for (int j = y1 - 1; j >= 0; j = ((j + 1) & j) - 1)
				{
					for (int k = z1 - 1; k >= 0; k = ((k + 1) & k) - 1)
					{
						sum += t[i][j][k];
					}
				}
			}
			
			for (int i = x1 - 1; i >= 0; i = ((i + 1) & i) - 1)
			{
				for (int j = y1 - 1; j >= 0; j = ((j + 1) & j) - 1)
				{
					for (int k = z1 - 1; k >= 0; k = ((k + 1) & k) - 1)
					{
						sum -= t[i][j][k];
					}
				}
			}
			fout << sum << "\n";
		}
	}
	return 0;
}

