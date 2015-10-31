#include <iostream>
#include <limits.h>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

bool stable(int a[], int i, int n)
{
    return (i == 0 || i == (n - 1) || (int)(a[i - 1] + a[i] + a[i + 1] > 1) == a[i]);
}

int main()
{
    int n = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool *p = new bool[n];
    int res = 0;
    //int *resa = new int[n];
    int l = 0, r = 0;
    int s[500005] = {};
    for (int i = 1; i < n - 1; i++)
    {
        s[i] = INT_MAX;
    }
    for (int i = 1; i < n - 1; i++)
    {
        //int s = a[i - 1] + a[i] + a[i + 1];
        p[i] = stable(a, i, n);
        if (!p[i])
        {
            r = i;
            if (l == 0)
                l = i;
        }
        //res += !p[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (stable(a, i, n))
            s[i] = 0;
        else
            s[i] = s[i - 1] + 1;
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (!stable(a, i, n))
            s[i] = min(s[i - 1], s[i + 1]) + 1;
    }
    res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] > res)
            res = s[i];
        a[i] = (a[i] + s[i]) & 1;
    }
    cout << res << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

