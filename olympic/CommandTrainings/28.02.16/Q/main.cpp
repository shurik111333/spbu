#include <iostream>
#include <fstream>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	//ifstream fin("in.txt");
	int t;
	cin >> t;
	char *f = new char[500];
	for (int i = 0; i < t; i++)
	{
		int c, j;
		cin >> c >> j;
		j++;
		cin >> f;
		int pos = 0;
		int count = 0;
		while (pos < c - 1)
		{
			int k;
			for (k = min(pos + j, c - 1); k > pos; k--)
			{
				if (f[k] == '.')
					break;
			}
			if (k <= pos)
			{
				count = -1;
				break;
			}
			pos = k;
			count++;
		}
		cout << count << "\n";
	}
	return 0;
}

