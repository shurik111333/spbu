#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int z[6100] = {};
//int zr[3100] = {};
char s[3100] = {}, t[3100] = {}, sr[3100] = {}, s1[6100] = {}, s2[6100] = {};
int len = 0;
int ans[2][3100] = {};

void zFunc(int start, char str[], int n, int z[])
{
    int l = 0;
    int r = 0;
    //int n = strlen(str);
    z[start] = n - start;
    for (int i = start + 1; i < n; i++)
    {
        z[i] = 0;
        if (i <= r)
            z[i] = min(z[i - l + start], r - i + 1);
        while (i + z[i] < n && str[i + z[i]] == str[z[i] + start])
        {
            z[i]++;
        }
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int main()
{
	cin >> s >> t;
	int lenS = strlen(s);
	int lenT = strlen(t);
	for (int i = 0; i < lenT; i++)
	{
		s1[i] = t[i];
		s2[i] = t[i];
	}
	s1[lenT] = '$';
	s2[lenT] = '$';
	for (int i = 0; i < lenS; i++)
	{
		s1[i + lenT + 1] = s[i];
		s2[i + lenT + 1] = s[lenS - i - 1];
	}
	len = lenS + lenT + 1;
	int p = 0;
	int res = 0;
	while (p < lenT)
	{
		zFunc(p, s1, len, z);
		int currRes = 0, x = 0, y = 0;
		for (int i = lenT + 1; i < len; i++)
		{
			if (z[i] > currRes)
			{
				currRes = z[i];
				x = i - lenT;
				y = x + z[i] - 1;
			}
		}
		zFunc(p, s2, len, z);
		for (int i = lenT + 1; i < len; i++)
		{
			if (z[i] > currRes)
			{
				currRes = z[i];
				x = lenS - (i - lenT - 1);
				y = x - z[i] + 1;
			}
		}
		if (currRes == 0)
		{
			cout << -1;
			return 0;
		}
		ans[0][res] = x;
		ans[1][res] = y;
		res++;
		p += currRes;
	}
	cout << res << "\n";
	for (int i = 0; i < res; i++)
	{
		cout << ans[0][i] << " " << ans[1][i] << "\n";
	}
	return 0;
}

