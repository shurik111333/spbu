#include <iostream>
#include <fstream>
#include <cstring>
#include <limits.h>

using namespace std;

int z[200005] = {};
int p[200005] = {};

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void zFunc(int start, int str[], int n)
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
    ifstream fin("invtrans.in");
    ofstream fout("invtrans.out");
    int n = 0;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> p[i];
    }
    int *str = new int[n + 1];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == 0)
        {
            str[i] = c;
            c++;
        }
        else
        {
            str[i] = str[p[i] - 1];
        }
    }
    zFunc(0, str, n);
    for (int i = 0; i < n; i++)
    {
        fout << z[i] << " ";
    }
    return 0;
}
