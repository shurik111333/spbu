#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("1.in");
ofstream fout("1.out");

int t;
int p[3][100];
int a[3][100];
int n;

void read(int a[])
{
    for (int i = 0; i < n; i++)
        fin >> a[i];
}

int main()
{
    fin >> t;
    for (int qq = 0; qq < t; qq++)
    {
        fin >> n;
        read(a[0]);
        read(a[1]);
        read(a[2]);
        int dp[3][10000] = {};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < n; j++)
            {
                p[i][a[i][j]] = j + 1;
                p[i][0] = INT_MAX;

                dp[i][1 << j] = j + 1;
                dp[i][0] = 0;
            }
        int q = (1 << n);
        for (int msk = 3; msk < q; msk++)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < n; j++)
                    if ((msk & (1 << j)) != 0 && dp[(i + 1) % 3][(msk ^ (1 << j))] > 0)
                    {
                        if (p[i][dp[i][msk]] > p[i][dp[(i + 1) % 3][(msk ^ (1 << j))]])
                            dp[i][msk] = dp[(i + 1) % 3][(msk ^ (1 << j))];
                    }
            }
        }
        fout << dp[0][q - 1] << "\n";
    }
    return 0;
}

