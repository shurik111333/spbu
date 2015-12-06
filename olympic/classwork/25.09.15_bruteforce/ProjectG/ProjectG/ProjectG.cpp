// ProjectG.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

int n = 0, m = 0, k = 0;
int e[3][300] = {};
int a[110][110] = {}, flags[110][110] = {};
int ind[110] = {}, val[110] = {};
bool result[110] = {};
int flag = 0;

void qSort(int left, int right)
{
	int leftIndex = left;
	int rightIndex = right;
	int comparingElement = e[0][(left + right) / 2];
	int comparingElement1 = e[1][(left + right) / 2];
	while (leftIndex < rightIndex)
	{
		while (e[0][leftIndex] < comparingElement || (e[0][leftIndex] == comparingElement && e[1][leftIndex] < comparingElement1))
		{
			leftIndex++;
		}
		while (e[0][rightIndex] < comparingElement || (e[0][rightIndex] == comparingElement && e[1][rightIndex] < comparingElement1))
		{
			rightIndex--;
		}
		if (leftIndex <= rightIndex)
		{
			swap(e[0][leftIndex], e[0][rightIndex]);
			swap(e[1][leftIndex], e[1][rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	}
	if (leftIndex < right)
	{
		qSort(leftIndex, right);
	}
	if (rightIndex > left)
	{
		qSort(left, rightIndex);
	}
}

void gen(int datCount, int currCount)
{
	if (flag != 0)
		return;
	if (currCount == m)
	{
		flag = 1;
		return;
	}
	if (datCount == k)
	{
		return;
	}
	int maxInd = -1;
	bool was[101] = {};
	for (int j = 1; j <= n; j++)
	{
		maxInd = -1;
		for (int i = 1; i <= n; i++)
		{
			if (!result[i] && !was[i])
			{
				if (maxInd == -1 || a[i][0] > a[maxInd][0])
				{
					maxInd = i;
				}
			}
		}
		was[maxInd] = true;
		result[maxInd] = true;
		for (int q = 1; q <= n; q++)
		{
			if (a[maxInd][q] == 1)
			{
				a[q][0]--;
			}
		}
		gen(datCount + 1, currCount + a[maxInd][0]);
		if (flag != 0)
			return;
		for (int q = 1; q <= n; q++)
		{
			if (a[maxInd][q] == 1)
			{
				a[q][0]++;
			}
		}
		result[maxInd] = false;
	}
}

int main()
{
	ifstream fin("piline.in");
	ofstream fout("piline.out");
	fin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		fin >> e[0][i] >> e[1][i];
		//e[0][i * 2 + 1] = e[1][i * 2];
		//e[1][i * 2 + 1] = e[0][i * 2];
		a[e[0][i]][e[1][i]] = 1;
		a[e[0][i]][0]++;
		a[e[1][i]][e[0][i]] = 1;
		a[e[1][i]][0]++;
	}
	/*for (int i = 1; i <= n; i++)
	{
		ind[i] = i;
		val[i] = a[i][0];
	}*/
	//qSort(0, m * 2);
	gen(0, 0);
	if (flag != 1)
	{
		fout << "NO";
	}
	else
	{
		fout << "YES" << endl;
		int c = 0;
		for (int i = 1; i <= n; i++)
		{
			if (result[i])
			{
				c++;
				fout << i << " ";
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (c == k)
				break;
			if (!result[i])
			{
				c++;
				fout << i << " ";
			}
		}
	}
	return 0;
}

