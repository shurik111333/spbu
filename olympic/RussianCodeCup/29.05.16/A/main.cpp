#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("1.in");

int t;
bool p[200];
int n, q;

int page(int x)
{
    int i = 0;
    while (x > 0)
    {
        i++;
        if (i > n)
            i = 1;
        if (p[i])
            x--;

    }
    return i;
}

void rem(int x)
{
    p[x] = false;
    p[n - x + 1] = false;
}

int main()
{
    cin >> t;
    for (int qq = 0; qq < t; qq++)
    {
        for (int i = 0; i < 200; i++)
            p[i] = true;
        cin >> n >> q;
        for (int i = 0; i < q; i++)
        {
            char c;
            int x;
            cin >> c >> x;
            if (c == '?')
                cout << page(x) << "\n";
            else
                rem(x);
        }
    }
    return 0;
}

