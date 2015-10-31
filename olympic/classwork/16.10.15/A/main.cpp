#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("fibstr.in");
    ofstream fout("fibstr.out");
    int n = 0, k = 0;
    fin >> n >> k;
    int res[50] = {};
    long long fib[50] = {};
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    int currIndex = 0;
    while (k > 0 && currIndex < n)
    {
        if (k >= fib[n - currIndex - 1])
        {
            res[currIndex] = 1;
            k -= fib[n - currIndex - 1];
            currIndex += 2;
        }
        else
        {
            currIndex++;
        }
    }
    if (n == 0)
        fout << " ";
    for (int i = 0; i < n; i++)
    {
        fout << res[i];
    }
    return 0;
}

