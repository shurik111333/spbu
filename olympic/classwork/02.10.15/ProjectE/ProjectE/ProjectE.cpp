// ProjectE.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

int abs(int a)
{
	if (a < 0)
		return -a;
	return a;
}

int main()
{
	ifstream fin("nearest.in");
	ofstream fout("nearest.out");
	int n = 0, a = 0;
	fin >> n >> a;
	int *v = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		fin >> v[i];
	}
	int currRes = v[0];
	char *c = new char[n + 1];
	for (int i = 1; i < n; i++)
	{
		if ()
	}
	return 0;
}

