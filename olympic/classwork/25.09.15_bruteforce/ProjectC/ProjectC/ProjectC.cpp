// ProjectC.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

int a[20][20] = {};
int result = 0;
int path[50] = {};
bool used[50] = {};
int results[1000000][15] = {};
int n = 0;
bool flags[20][20];

bool check(int path[], int count, int vertex)
{
	int p[20] = {};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			flags[i][j] = false;
		}
	}
	int ind = 0;
	for (int i = 1; i <= count; i++)
	{
		if (path[i] == vertex)
		{
			ind = i;
			break;
		}
	}
	for (int i = ind; i < count; i++)
	{
		flags[path[i]][path[i + 1]] = true;
		flags[path[i + 1]][path[i]] = true;
	}
	flags[path[count]][path[ind]] = true;
	flags[path[ind]][path[count]] = true;
	bool flag = false;
	for (int i = 0; i < result; i++)
	{
		if ((count - ind + 1) != results[i][0])
			continue;
		/*int p1[20] = {};
		int c = 0;
		for (int j = 1; j <= count; j++)
		{
			p1[results[i][j]]++;
		}
		for (int j = 1; j <= n; j++)
		{
			if (p[j] == p1[j])
				c++;
		}*/
		int c = 0;

		for (int j = 1; j < results[i][0]; j++)
		{
			if (flags[results[i][j]][results[i][j + 1]])
				c++;
		}
		if (flags[results[i][results[i][0]]][results[i][1]])
			c++;
		/*int ind1 = 0;
		for (int j = 1; j <= results[i][0]; j++)
		{
			if (results[i][j] == path[ind])
			{
				ind1 = j;
				break;
			}
		}
		if (ind1 == 0)
		{
			continue;
		}


		int ind_t = ind;
		int ind1_t = ind1;
		for (int j = 1; j <= results[i][0]; j++)
		{
			if (path[ind_t] == results[i][ind1_t])
				c++;
			ind_t++;
			ind1_t++;
			if (ind1_t > results[i][0])
			{
				ind1_t = 1;
			}
		}*/

		if (c == results[i][0])
		{
			flag = true;
			break;
		}
	}
	return !flag;
}

void dfs(int vertex, int prevVertex, int count, int minVertex)
{
	used[vertex] = true;
	path[count] = vertex;
	for (int i = minVertex; i <= n; i++)
	{
		if (a[vertex][i] == 1)
		{
			if (!used[i])
			{
				dfs(i, vertex, count + 1, minVertex);
			}
			else
			{
				if (i != prevVertex && i == minVertex)
				{
					/*int ind = 0;
					for (int j = 1; j <= count; j++)
					{
						if (path[j] == i)
						{
							ind = j;
							break;
						}
					}
					results[result][0] = count - ind + 1;
					for (int j = 1; j <= results[result][0]; j++)
					{
						results[result][j] = path[j + ind - 1];
					}*/
					result++;
				}
			}
		}
	}
	used[vertex] = false;
}

int main()
{
	ifstream fin("numcycle.in");
	ofstream fout("numcycle.out");
	n = 0;
	int m = 0;
	fin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		fin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	/*for (int i = 1; i <= n; i++)
	{
		dfs(i, 0, 1);
	}*/
	//int result = 0;
	for (int i = 1; i < n; i++)
	{
		dfs(i, 0, 1, i);
	}
	fout << result / 2 << endl;
	/*for (int i = 0; i < result; i++)
	{
		for (int j = 1; j <= results[i][0]; j++)
		{
			fout << results[i][j] << " ";
		}
		fout << endl;
	}*/
	return 0;
}

