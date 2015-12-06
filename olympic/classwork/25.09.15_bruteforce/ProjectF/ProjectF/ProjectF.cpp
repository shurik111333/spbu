// ProjectF.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>

using namespace std;

int p[100000] = {}, s[100000] = {};

long long Power(int a, int b)
{
	if (b == 0)
		return 1;
	else
	{
		if ((b & 1) == 1)
			return a * Power(a, b - 1);
		else
		{
			long long t = Power(a, b / 2);
			return t * t;
		}
	}
}

int main()
{
	ifstream fin("refrigerator.in");
	ofstream fout("refrigerator.out");
	int t = 0;
	fin >> t;
	for (int qq = 0; qq < t; qq++)
	{
		int k = 0;
		fin >> k;
		p[0] = 1;
		s[0] = 3;
		long long n = 1;
		for (int i = 1; i <= k; i++)
		{
			fin >> p[i] >> s[i];
			n *= Power(p[i], s[i]);
		}
		long long Min = -1;
		long long aRes = 0;
		long long bRes = 0;
		long long cRes = 0;
		for (int i = 0; i <= k; i++)
		{
			for (int q = 1; q <= s[i]; q++)
			{
				s[i] -= q;
				for (int j = 0; p[j] <= n / p[i] && j <= k; j++)
				{
					if (s[j] > 0)
					{
						long long c = n / (p[i] * p[j]);
						if (Min == -1 || Min > 2 * (p[i] * p[j] + p[j] * c + p[i] * c))
						{
							Min = 2 * (p[i] * p[j] + p[j] * c + p[i] * c);
							aRes = p[i];
							bRes = p[j];
							cRes = c;
						}
					}
				}
				s[i] += q;
			}
		}
		fout << Min << " " << aRes << " " << bRes << " " << cRes << endl;
	}
	return 0;
}

