// ProjectA.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

int main()
{
	ifstream fin("fib.in");
	ofstream fout("fib.out");
	int n = 0;
	fin >> n;
	long long *res = new long long[n + 1];
	res[0] = 1;
	res[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		res[i] = res[i - 1] + res[i - 2];
	}
	fout << res[n];
	return 0;
}

