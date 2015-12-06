#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <string>

using namespace std;

const int maxLen = 100005;

int z[200005] = {};
int p1[200005] = {};


int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void zFunc(int start, char *str)
{
    int l = 0;
    int r = 0;
    int n = strlen(str);
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
    ifstream fin("substr.in");
    ofstream fout("substr.out");
    char inputStr1[maxLen] = {};
    fin >> inputStr1;
    int n = strlen(inputStr1);
    int result = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        zFunc(i, inputStr1);
        for (int j = i + 1; j < n; j++)
        {
            result -= max(0, z[j] - p1[j]);
            p1[j] = max(p1[j], z[j]);
        }
    }
    fout << result;
    return 0;
}
