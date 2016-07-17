#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("1.in");

int t;
bool p[200];
int n, m;
int a[10000], b[10000];


int main()
{
    cin >> t;
    for (int qq = 0; qq < t; qq++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        int r = n - 1;
        int s = 0;
        string s1;
        cin >> s1;
        int money = 0;
        int ans = 0;
        for (char c : s1)
        {
            if (c == '+')
                money += a[r--];
            else
            {
                if (money < b[s])
                {
                    ans++;
                    continue;
                }
                money -= b[s++];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

