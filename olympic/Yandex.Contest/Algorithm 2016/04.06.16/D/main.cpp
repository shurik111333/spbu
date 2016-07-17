#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int p, m, w;
int mod = 1e9 + 7;

ll f[2001000];


int main()
{
    cin >> m >> w >> p;
    //m = w = 1000000;
    //p = 1001;

    f[0] = 1;
    for (int i = 1; i <= m + w; i++)
    {
        f[i] = (f[i - 1] * i) % mod;
    }
    if (p == 0)
    {
        if ((((ll)m) * w) != 0)
            cout << 0;
        else
            cout << f[max(m, w)];
        return 0;
    }
    ll res1 = 0;
    if (p > 1)
        res1 = (((f[w] * f[m]) % mod) * 2) % mod;
    if (p == min(m, w))
    {
        cout << (((((((f[max(m, w) - p] * f[p / 2]) % mod) * f[p - p / 2]) % mod) * 2) % mod) + res1) % mod;
        return 0;
    }
    ll res = 0;
    if ((p % 2) == 0)
    {
        res = 0;
    }
    else
        res = (((((((f[w - p] * f[p / 2]) % mod) * f[p - p / 2]) % mod) * f[m - p]) % mod) * 2) % mod;
    cout << ((res + res1) % mod);

    return 0;
}

