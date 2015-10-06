// ProjectA.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int p1[100] = {}, p2[100] = {}, h[10000] = {}, v[10000] = {}, res[10000] = {};
	int result = 0;
	for (int i = 0; i < n * n; i++)
	{
		cin >> h[i] >> v[i];
		if (p1[h[i]] == 0 && p2[v[i]] == 0)
		{
			res[result] = i;
			result++;
			p1[h[i]] = 1;
			p2[v[i]] = 1;
		}
	}
	for (int i = 0; i < result; i++)
	{
		cout << res[i] + 1 << " ";
	}
    return 0;
}

