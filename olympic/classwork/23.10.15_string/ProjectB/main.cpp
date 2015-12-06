#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int maxLen = 100005;

long long h[100005] = {};
int p = 41;
int m = 1000000000 + 7;
long long pow[100005] = {};
int result[100005] = {};


void hash1(char *s)
{
    int len = strlen(s);
    h[0] = s[0];
    for (int i = 1; i < len; i++)
    {
        h[i] = (h[i - 1] * p + s[i]) % m;
    }
}

void calcPow(int n)
{
    pow[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pow[i] = (pow[i - 1] * p) % m;
    }
}

int hash1(int l, int r)
{
    if (l == 0)
        return h[r];
    else
        return ((h[r] - (h[l - 1] * pow[r - l + 1]) % m) + m) % m;
}

int main()
{
    ifstream fin("substrcmp.in");
    ofstream fout("substrcmp.out");
    char *inputStr1 = new char[maxLen];
    fin >> inputStr1;
    calcPow(strlen(inputStr1));
    hash1(inputStr1);
    int m = 0;
    fin >> m;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, c = 0, d = 0;
        fin >> a >> b >> c >> d;
        if (hash1(a - 1, b - 1) == hash1(c - 1, d - 1))
            fout << "Yes";
        else
            fout << "No";
        fout << endl;
    }
    return 0;
}
