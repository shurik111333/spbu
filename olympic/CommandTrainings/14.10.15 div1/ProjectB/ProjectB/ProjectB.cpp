#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("bureau.in");
	ofstream fout("bureau.out");
	int n = 0;
	string s;
	int q[100001] = {};
	bool f[100001] = {};
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> s;
		if (s == "cancel")
			fin >> q[i];
		else
			q[i] = 0;
	}
	for (int i = n; i > 0; i--)
		if (!f[i])
		{
			if (q[i] != 0)
				f[q[i]] = true;
		}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (!f[i])
			sum++;
	fout << sum << endl;
	for (int i = 1; i <= n; i++)
		if (!f[i])
			fout << i << " ";
	return 0;
}

