// ProjectC.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	char *s1 = new char[n], *s2 = new char[n], *s3 = new char[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s1[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s2[i];
		if (s2[i] == s1[i])
		{
			s3[i] = s1[i];
			count++;
		}
	}
	if (n - count <= t)
	{
		for (int i = 0; i < n; i++)
		{
			if (s1[i] != s2[i])
			{
				if (s1[i] != 'a' && s2[i] != 'a')
				{
					s3[i] = 'a';
				}
				if (s1[i] != 'b' && s2[i] != 'b')
				{
					s3[i] = 'b';
				}
				if (s1[i] != 'c' && s2[i] != 'c')
				{
					s3[i] = 'c';
				}
			}
		}
		count = t - (n - count);
		for (int i = 0; i < n; i++)
		{
			if (count > 0 && s1[i] == s2[i])
			{
				count--;
				if (s1[i] != 'a')
				{
					s3[i] = 'a';
				}
				if (s1[i] != 'b')
				{
					s3[i] = 'b';
				}
			}
			cout << s3[i];
		}
	}
	else
	{
		//cout << -1;

	}
	system("pause");
	return 0;
}

