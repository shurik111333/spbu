// ProjectG.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

int n = 0, m = 0, k = 0;
//int e[3][300] = {};
int a[2100][2100] = {};
bool flags[2100][2100] = {};
//int ind[2100] = {}, val[2100] = {};
//bool was[2100] = {};
bool result[2100] = {};
int flag = 0;

/*void qSort(int left, int right)
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
}*/

void gen(int datCount, int currCount)
{
	if (flag != 0)
		return;
	if (currCount >= m && datCount <= k)
	{
		flag = 1;
		return;
	}
	if (datCount >= k)
	{
		return;
	}
	int maxInd = -1;
	/*for (int i = 1; i <= n; i++)
	{
		was[i] = false;
	}*/
	/*bool *was = new bool[n + 1];
	for (int i = 1; i <= n; i++)
	{
		was[i] = false;
	}*/
	//for (int j = 1; j <= n; j++)
	//{
		//maxInd = -1;
		for (int i = 1; i <= n; i++)
		{
			if (!result[i])// && !was[i])
			{
				if (maxInd == -1 || a[i][0] > a[maxInd][0])
				{
					maxInd = i;
				}
			}
		}
		/*if (a[maxInd][0] == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[maxInd][i] == 1)
				{
					maxInd = 1;
					break;
				}
			}
		}*/
		//was[maxInd] = true;
		result[maxInd] = true;
		for (int q = 1; q <= n; q++)
		{
			if (a[maxInd][q] == 1 && !flags[maxInd][q])
			{
				a[q][0]--;
				flags[maxInd][q] = true;
				flags[q][maxInd] = true;
			}
		}
		currCount += a[maxInd][0];
		a[maxInd][0] = 0;

		gen(datCount + 1, currCount);

		if (flag != 0)
			return;
		for (int q = 1; q <= n; q++)
		{
			if (a[maxInd][q] == 1 && !result[q])
			{
				flags[maxInd][q] = false;
				flags[q][maxInd] = false;
			}
		}
		//datCount += a[maxInd][0];
		for (int q = 1; q <= n; q++)
		{
			if (a[maxInd][q] == 1 && !flags[maxInd][q])
			{
				if (datCount >= k)
				{
					//flag = -1;
					return;
				}
				a[q][0]++;
				result[q] = true;
				datCount++;
				currCount += a[q][0];
				for (int qq = 1; qq <= n; qq++)
				{
					if (a[q][qq] == 1 && !flags[q][qq])
					{
						flags[q][qq] = true;
						flags[qq][q] = true;
						a[qq][0]--;
					}
				}
				a[q][0] = 0;
			}
		}
		result[maxInd] = false;
		gen(datCount, currCount);
	//}

}

int main()
{
	ifstream fin("pipeline.in");
	ofstream fout("pipeline.out");
	fin >> n >> m >> k;
	int e1, e2;
	for (int i = 0; i < m; i++)
	{
		fin >> e1 >> e2;
		//e[0][i * 2 + 1] = e[1][i * 2];
		//e[1][i * 2 + 1] = e[0][i * 2];
		a[e1][e2] = 1;
		a[e1][0]++;
		a[e2][e1] = 1;
		a[e2][0]++;
	}
	/*for (int i = 1; i <= n; i++)
	{
	ind[i] = i;
	val[i] = a[i][0];
	}*/
	//qSort(0, m * 2);
	int sensCount = 0, edgesCount = 0;
	int Min = 0;
	//bool flags[100][100] = {};
	int maxi = 0;
	/*while (sensCount < k)
	{
		maxi = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i][0] > a[maxi][0])
			{
				maxi = i;
			}
		}
		if (a[maxi][0] > (k - sensCount))
		{
			result[maxi] = true;
			sensCount++;
			edgesCount += a[maxi][0];
			for (int j = 1; j <= n; j++)
			{
				if (a[maxi][j] == 1 && !flags[maxi][j])
				{
					flags[maxi][j] = true;
					flags[j][maxi] = true;
					a[j][0]--;
				}
			}
			a[maxi][0] = 0;
		}
		else
			break;
	}*/
	while (sensCount < k)
	{
		Min = -1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i][0] == 1)
			{
				Min = i;
				break;
			}
		}
		if (Min == -1)
		{
			break;
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[Min][i] == 1 && !flags[Min][i])
			{
				//flags[Min][i] = true;
				//flags[i][Min] = true;
				result[i] = true;
				sensCount++;
				edgesCount += a[i][0];
				for (int j = 1; j <= n; j++)
				{
					if (a[i][j] == 1 && !flags[i][j])
					{
						flags[i][j] = true;
						flags[j][i] = true;
						a[j][0]--;
					}
				}
				a[i][0] = 0;
				break;
			}
		}
	}
	gen(sensCount, edgesCount);
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