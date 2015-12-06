#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int first[210000] = {}, next1[410000] = {}, val[410000] = {};
int used[210000] = {}, pow[210000] = {}, topSort[210000] = {};
int countVal = 0;
bool isFind = false;
ofstream fout("topsort.out");

void add(int a, int b)
{
    countVal++;
    val[countVal] = b;
    if (first[a] == 0)
    {
        first[a] = countVal;
        return;
    }
    next1[countVal] = first[a];
    first[a] = countVal;
}

void dfs(int v)
{
    used[v] = 1;
    int k = first[v];
    while (k != 0)
    {
        if (used[val[k]] == 0)
            dfs(val[k]);
        if (isFind)
            return;
        if (used[val[k]] == 1)
        {
            isFind = true;
            return;
        }
        k = next1[k];
    }
    used[v] = 2;
    topSort[++topSort[0]] = v;
}

int main()
{
    ifstream fin("topsort.in");
    fout.sync_with_stdio(false);
    int n = 0, m = 0;
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        fin >> a >> b;
        pow[b]++;
        add(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0)
            dfs(i);
    }
    if (isFind)
        fout << -1;
    else
    {
        for (int i = topSort[0]; i > 0; i--)
        {
            fout << topSort[i] << " ";
        }
    }
    return 0;
}
