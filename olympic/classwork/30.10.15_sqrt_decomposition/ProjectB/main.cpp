#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

long long a[110000] = {};
long long g[110000] = {};
int n, k;
int size;

long long sum(int l, int r)
{
    long long result = 0;
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

int main()
{
    ifstream fin("sum.in");
    ofstream fout("sum.out");
    fout.sync_with_stdio(false);
    fin >> n >> k;
    int d, e;
    if (k == 0)
        fout << "\n";
    size = sqrt(n);
    for (int i = 0; i < k; i++)
    {
        char c;
        fin >> c >> d >> e;
        d--;
        if (c == 'Q')
        {
            fout << sum(d, e - 1) << endl;
        }
        else
        {
            g[(d) / size] += e - a[d];
            a[d] = e;
        }
    }
    return 0;
}
