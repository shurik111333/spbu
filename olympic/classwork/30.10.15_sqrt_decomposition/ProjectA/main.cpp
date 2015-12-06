#include <iostream>
#include <fstream>

using namespace std;

//int a[10000005] = {};
long long sum[10000005] = {};
//long long b[21000000] = {};
int c[21000005] = {};
int m1 = 65536;
int m2 = 1073741824;

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    ifstream fin("sum0.in");
    ofstream fout("sum0.out");
    int n, x, y, a0;
    fin >> n >> x >> y >> a0;
    //a[0] = a0;
    sum[0] = a0;
    for (int i = 1; i < n; i++)
    {
        a0 = (x * a0 + y) % m1;
        sum[i] = sum[i - 1] + a0;
    }
    int m, z, t;
    long long b0;
    fin >> m >> z >> t >> b0;
    //b[0] = b0;
    c[0] = b0 % n;
    long long result = 0;
    for (int i = 1; i < 2 * m + 1; i++)
    {
        b0 = ((z * b0 + t) + m2);
        b0 %= m2;
        c[i] = b0 % n;
    }
    for (int i = 0; i < m; i++)
    {
        result += sum[max(c[2 * i], c[2 * i + 1])];
        if (min(c[2 * i], c[2 * i + 1]) > 0)
            result -= sum[min(c[2 * i], c[2 * i + 1]) - 1];
    }
    fout << result;
    return 0;
}
