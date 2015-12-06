#include <iostream>
#include <fstream>

using namespace std;

int d[2][10000] = {};

const int module = 1000000000 + 7;

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

int main()
{
    ifstream fin("fixedsum.in");
    ofstream fout("fixedsum.out");
    int k = 0, s = 0;
    fin >> k >> s;
    for (int i = 0; i < 10; i++)
    {
        d[1][i] = 1;
    }
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j <= s; j++)
            d[(i + 1) & 1][j] = 0;
        for (int j = 0; j <= min(s, i * 9); j++)
        {
            for (int q = 0; (q < 10) && (j + q <= s); q++)
            {
                d[(i + 1) & 1][j + q] += d[i & 1][j];
                if (d[(i + 1) & 1][j + q] >= module)
                    d[(i + 1) & 1][j + q] %= module;
            }
        }
    }
    fout << d[k & 1][s] % module;
    return 0;
}
