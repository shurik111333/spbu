#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int p, a, b;
    cin >> p >> a >> b;
    int res = 0;
    if (p < b)
    {
        cout << -1;
        return 0;
    }
    cout << max(p, a + b);
    return 0;
}

