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
    ifstream fin("search.in");
    ofstream fout("search.out");
    char *inputStr1 = new char[maxLen];
    char *inputStr2 = new char[maxLen];
    fin >> inputStr1;
    fin >> inputStr2;
    calcPow(strlen(inputStr1));
    hash1(inputStr1);
    long long h1 = inputStr2[0];
    int len = strlen(inputStr2);
    for (int i = 1; i < len; i++)
    {
        h1 = (h1 * p + inputStr2[i]) % m;
    }
    int len1 = strlen(inputStr1);
    int res = 0;
    for (int i = 0; i < len1 - len + 1; i++)
    {
        long long h2 = hash1(i, i + len - 1);
        if (h2 == h1)
        {
            result[res] = i + 1;
            res++;
        }
    }
    fout << res << endl;
    for (int i = 0; i < res; i++)
    {
        fout << result[i] << " ";
    }
    return 0;
}

