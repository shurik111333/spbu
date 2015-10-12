#include <iostream>
#include <limits.h>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("diameter.in", "r", stdin);
    freopen("diameter.out", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    int a[200][200] = {};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == -1)
                a[i][j] = INT_MAX / 2;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //if (a[i][j] != -1 && a[i][k] != -1 && a[k][j] != -1)
                {
                    if (a[i][j] > a[i][k] + a[k][j])
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }
    int diametr = -1;
    int radius = -1;
    int max1;
    for (int i = 1; i <= n; i++)
    {
        max1 = -1;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                if (diametr == -1 || diametr < a[i][j])
                    diametr = a[i][j];
                if (max1 == -1 || max1 < a[i][j])
                {
                    max1 = a[i][j];
                }
            }
        }
        if (radius == -1 || radius > max1)
        {
            radius = max1;
        }
    }
    printf("%d\n%d", diametr, radius);
    return 0;
}

