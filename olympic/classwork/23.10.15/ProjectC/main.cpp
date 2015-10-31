#include <iostream>
#include <fstream>

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

int main()
{
    ifstream fin("trans.in");
    ofstream fout("trans.out");
    int n = 0;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> z[i];
    }
    p[0] = 0;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        //p[i + z[i] - 1] = max(p[i + z[i] - 1], z[i]);
        for (int j = max(i, r); j < i + z[i]; j++)
        {
            p[j] = max(p[j], j - i + 1);
        }
        r = max(r, i + z[i] - 1);
    }
    for (int i = 0; i < n; i++)
    {
        fout << p[i] << " ";
    }
    return 0;
}

