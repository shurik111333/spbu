#include <iostream>
#include <fstream>

using namespace std;

int first[110000] = {}, next1[210000] = {}, val[210000] = {};
int used[110000] = {}, topSort[110000] = {};
int countVal = 0;
bool isFind = false;
ofstream fout("unitopsort.out");

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
    //ind[v] = topSort[0];
}

int main()
{
    ifstream fin("unitopsort.in");
    fout.sync_with_stdio(false);
    int n = 0, m = 0;
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        fin >> a >> b;
        //pow[b]++;
        add(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0)
            dfs(i);
    }
    bool isOnce = true;
    for (int i = n; i > 1; i--)
    {
        int k = first[topSort[i]];
        bool res = true;
        while (k != 0)
        {
            if (topSort[i - 1] == val[k])
            {
                res = false;
                break;
            }
            k = next1[k];
        }
        if (res)
        {
            isOnce = false;
            break;
        }
    }
    if (isOnce)
    {
        fout << "YES\n";
        for (int i = n; i > 0; i--)
        {
            fout << topSort[i] << " ";
        }
    }
    else
        fout << "NO";
    return 0;
}
