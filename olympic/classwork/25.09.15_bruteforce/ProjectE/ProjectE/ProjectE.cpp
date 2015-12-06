// ProjectE.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>
#include <limits.h>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin("refrator.in");
	ofstream fout("refrator.out");
	long long n = 0;
	for (n = 1; n < 1000; n++)
	{
		//fin >> n;
		long long Min = -1;
		long long aRes = 0;
		long long bRes = 0;
		long long cRes = 0;
		long long aMax = (long long)pow(n, 1.0 / 3) + 1;
		long long bMax = 0;
		long long c = 0;
		for (long long a = 1; a <= aMax; a++)
		{
			if (n % a == 0)
			{
				bMax = (long long)sqrt(n / a) + 1;
				for (long long b = 1; b <= bMax; b++)
				{
					c = n / (a * b);
					if (a * b * c == n && (2 * (a * b + b * c + c * a) < Min || Min == -1))
					{
						aRes = a;
						bRes = b;
						cRes = c;
						Min = 2 * (a * b + b * c + c * a);
					}
				}
			}
		}
		fout << "-----------------------------------" << endl;
		fout << 1 << " ";
		for (int i = 2; i <= n / 2; i++)
		{
			if (n % i == 0)
			{
				fout << i << " ";
			}
		}
		fout << n << endl;
		fout << Min << " " << aRes << " " << bRes << " " << cRes << endl;
	}
	return 0;
}