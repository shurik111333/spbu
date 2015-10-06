// ProjectD.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

int search(int l, int r, long long x, int Array[])
{
	long long left = l;
	long long right = r;
	long long middle = 0;
	while (right - left > 1)
	{
		middle = (left + right) / 2;
		if (Array[middle] < x)
		{
			right = middle;
		}
		else
		{
			left = middle + 1;
		}
	}
	if (Array[left] < x)
		return left;
	return right;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int a[1000] = {};
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int dp[1000] = {}, p[1000] = {}, d[1000] = {};
	dp[n + 1] = _I64_MIN;
	dp[0] = _I64_MAX;
	for (int i = 0; i < n; i++)
	{
		int ind = search(0, n, a[i], dp);
		if (ind == 0 || dp[ind - 1] >= a[i])
		{
			if (dp[ind] > a[i])
			{
				dp[ind] = a[i];
				p[ind] = i + 1;
				d[i + 1] = p[ind - 1];
			}
		}
	}
	return 0;
}

