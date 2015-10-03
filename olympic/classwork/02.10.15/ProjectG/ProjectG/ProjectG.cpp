// ProjectG.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>
#include <limits.h>


using namespace std;

int search(int l, int r, long long x, long long Array[])
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
	ifstream fin("subseq.in");
	ofstream fout("subseq.out");
	int n = 0;
	fin >> n;
	long long *a = new long long[n + 2];
	int *p = new int[n + 2];
	long long *dp = new long long[n + 2];
	int *d = new int[n + 2];
	/*long long a[300000] = {}, dp[300000] = {};
	int p[300000] = {}, d[300000] = {};*/
	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
		p[i] = 0;
		dp[i + 1] = _I64_MIN;
		d[i] = 0;
	}
	dp[n + 1] = _I64_MIN;
	dp[0] = _I64_MAX;
	for (int i = 0; i < n; i++)
	{
		int ind = search(0, n, a[i], dp);
		if (ind == 0 || dp[ind - 1] >= a[i])
		{
			if (dp[ind] < a[i])
			{
				dp[ind] = a[i];
				p[ind] = i + 1;
				d[i + 1] = p[ind - 1];
			}
		}
	}
	int count = 0;
	while (dp[count + 1] > _I64_MIN)
	{
		count++;
	}
	//fout << count << endl;
	//fout << p[count] << endl;
	int *res = new int[n + 1];
	int ind = p[count];
	res[0] = ind;
	count = 1;
	while (d[ind] > 0)
	{
		//count++;
		//fout << d[count] << endl;
		res[count] = d[ind];
		count++;
		ind = d[ind];
	}
	fout << count << endl;
	for (int i = count - 1; i >= 0; i--)
	{
		fout << res[i] << endl;
	}
	return 0;
}