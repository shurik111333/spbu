// ProjectB.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>
#include <limits.h>
#include <ctime>

using namespace std;

long long Min = INT_MAX;
int result[40] = {};
int path[20] = {};
int n;
int ind[20][20] = {};
int a[20][20] = {};
int a1[20][20] = {};
int count1 = 0;
clock_t start;

long long max(long long a, long long b)
{
	if (a > b)
		return a;
	else
		return b;
}

void qSort(int left, int right, int index)
{
	int leftIndex = left;
	int rightIndex = right;
	int comparingElement = a[index][(left + right) / 2];
	while (leftIndex < rightIndex)
	{
		while (a[index][leftIndex] < comparingElement)
		{
			leftIndex++;
		}
		while (a[index][rightIndex] > comparingElement)
		{
			rightIndex--;
		}
		if (leftIndex <= rightIndex)
		{
			swap(a[index][leftIndex], a[index][rightIndex]);
			swap(ind[index][leftIndex], ind[index][rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	}
	if (leftIndex < right)
	{
		qSort(leftIndex, right, index);
	}
	if (rightIndex > left)
	{
		qSort(left, rightIndex, index);
	}
}

void search(long long cost, bool used[], int path[], int vertex, long long Max)
{
	if ((double)(clock() - start) / CLOCKS_PER_SEC < 1.8)
	{
		used[vertex] = true;
		count1++;
		path[count1] = vertex;
		if (count1 == n)
		{
			if ((cost + a1[vertex][1] - max(Max, a1[vertex][1])) < Min)
			{
				Min = cost + a1[vertex][1] - max(Max, a1[vertex][1]);
				for (int i = 1; i <= n; i++)
				{
					result[i] = path[i];
				}
				//result[n + 1] = 1;
			}
		}
		else
		{
			if (cost - Max <= Min)
			{
				for (int i = 1; i <= n; i++)
				{
					if (!used[ind[vertex][i]] && ind[vertex][i] != vertex)
					//if (!used[i] && i != vertex)
					{
						//used[i] = true;
						//path[count + 1] = i;
						search(cost + a[vertex][i], used, path, ind[vertex][i], max(Max, a[vertex][i]));
						//search(cost + a[vertex][i], used, path, i, max(Max, a[vertex][i]));
						//used[i] = false;
					}
				}
			}
		}
	}
	count1--;
	used[vertex] = false;
}

int main()
{
	ifstream fin("aquarium.in");
	ofstream fout("aquarium.out");
	n = 0;
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			fin >> a[i][j];
			a1[i][j] = a[i][j];
			ind[i][j] = j;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		qSort(1, n, i);
	}
	bool used[20] = {};
	start = clock();
	//for (int i = 1; i <= n; i++)
	//{
		//used[i] = true;
		search(0, used, path, 1, -1);
		//used[i] = false;
	//}
	fout << Min << endl;
	for (int i = n + 1; i <= 2 * n; i++)
	{
		result[i] = result[i - n];
	}
	long long indMax = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a1[result[indMax]][result[indMax + 1]] < a1[result[i]][result[i + 1]])
		{
			indMax = i;
		}
	}
	long long currInd = indMax + 1;
	for (int i = 1; i <= n; i++)
	{
		fout << result[currInd] << " ";
		currInd++;
	}
	return 0;
}