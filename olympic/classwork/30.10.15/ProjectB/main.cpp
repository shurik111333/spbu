#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

long long a[110000] = {};
long long g[110000] = {};
long long upd[110000] = {};
int n, k;
int size;

void setUpdate(int ind)
{
    if (upd[ind / size] == -1)
        return;
    int group = ind / size;
    for (int i = (group) * size; i < (group + 1) * size; i++)
    {
        a[i] = upd[group];
    }
    upd[group] = -1;
}

long long sum(int l, int r)
{
    long long result = 0;
    setUpdate(l);
    if (l / size == r / size)
    {
        for (int i = l; i <= r; i++)
            result += a[i];
        return result;
    }
    for (int i = l; i < (l / size + 1) * size; i++)
    {
        result += a[i];
    }
    setUpdate(r);
    for (int i = r; i >= (r / size) * size; i--)
    {
        result += a[i];
    }
    for (int i = l / size + 1; i < r / size; i++)
    {
        result += g[i];
    }
    return result;
}

void update(int l, int r, long long x)
{
    setUpdate(l);
    if (l / size == r / size)
    {
        for (int i = l; i <= r; i++)
        {
            g[l / size] += x - a[i];
            a[i] = x;
        }
        return;
    }
    for (int i = l; i < (l / size + 1) * size; i++)
    {
        g[l / size] += x - a[i];
        a[i] = x;
    }
    setUpdate(r);
    for (int i = r; i >= (r / size) * size; i--)
    {
        g[r / size] += x - a[i];
        a[i] = x;
    }
    for (int i = l / size + 1; i < r / size; i++)
    {
        upd[i] = x;
        g[i] = x * size;
    }
}

int main()
{
    ifstream fin("sum2.in");
    ofstream fout("sum2.out");
    fout.sync_with_stdio(false);
    fin >> n >> k;
    int l, r;
    if (k == 0)
        fout << "\n";
    size = sqrt(n);
    for (int i = 0; i <= size; i++)
    {
        upd[i] = -1;
    }
    for (int i = 0; i < k; i++)
    {
        char c;
        fin >> c >> l >> r;
        l--;
        r--;
        if (c == 'Q')
        {
            fout << sum(l, r) << endl;
        }
        else
        {
            long long x;
            fin >> x;
            update(l, r, x);
        }
    }
    return 0;
}

