#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	long long n;
	cin >> n;
	long long mas[110500];
	mas[0]=0;
	mas[1]=0;
	for (int i = 2; i <= n; i++)
		mas[i] = 1;
	for (int j = 2; j <= n; j++)
	{
		long long degj = 1;
		long long res = 1;
		while (res <= n){
			degj *= j;
			res += degj;
			if (res > n)
				break;
			mas[res]++;
		}
	}
	long long mask[110500] = {};
	for (int i = 0; i <= n; i++)
		mask[i] = 0;
	for (int i = 2; i <= n; i++)
	{
		int x = sqrt(i);
		for (int k = 2; k <= x; k++)
		{
			if ((i % k) == 0)
			{
				mask[i] += mas[i / k];
				if (((i / k) != k))
				{
					mask[i] += mas[k];
				}
			}
		}
	}
	cout << mas[n] + mask[n];
	return 0;
}

