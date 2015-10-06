// ProjectB.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int a[1100] = {}, p[1100] = {};
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		p[i] = 0;
	}
	int turns = -1;
	int inf = 0;
	while (inf < n)
	{
		turns++;
		if ((turns % 2) == 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] <= inf && p[i] != 1)
				{
					p[i] = 1;
					inf++;
				}
			}
		}
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{
				if (a[i] <= inf && p[i] != 1)
				{
					p[i] = 1;
					inf++;
				}
			}
		}
	}
	if (turns < 0)
	{
		turns = 0;
	}
	cout << turns;
	return 0;
}

