#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int p[30] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
ll sc[10];
ll sc1[10];

int main()
{
    for (int i = 0; i < 10; i++)
        cin >> sc[i];
    sort(sc, sc + 10);
    for (int i = 0; i < 10; i++)
    {
        sc1[i] = sc[i];
        sc[i] += p[i];
    }
    sort(sc, sc + 10);
    if (sc[0] < 0)
    {
        cout << 1000;
        return 0;
    }
    for (int i = 29; i >= 10; i--)
    {
        if (p[i] > sc[0])
        {
            cout << i + 1;
            return 0;
        }
    }
    for (int k = 9; k >= 0; k--)
    {
        for (int i = 0; i < 10; i++)
            sc[i] = sc1[i];
        int c = 0;
        for (int i = 0; i < 10; i++)
        {
            if (i == k)
                c++;
            sc[i] += p[c++];
        }
        sort(sc, sc + 10);
        if (sc[0] < p[k])
        {
            cout << k + 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

