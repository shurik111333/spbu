#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int first[210000] = {}, next1[410000] = {}, val[410000] = {};
int used[210000] = {}, path[210000] = {};
int countVal = 0;
bool isFind = false;
ofstream fout("cycle.out");

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
    path[0]++;
    path[path[0]] = v;
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
            fout << "YES\n";
            /*for (int i = path[0]; i > 0; i--)
            {
                fout << path[i] << " ";
                if (path[i] == val[k])
                    break;
            }*/
            int ind = path[0];
            while (path[ind] != val[k])
                ind--;
            for (int i = ind; i <= path[0]; i++)
            {
                fout << path[i] << " ";
            }
        }
        k = next1[k];
    }
    used[v] = 2;
    path[0]--;
}

int main()
{
    ifstream fin("cycle.in");
    fout.sync_with_stdio(false);
    int n = 0, m = 0;
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        fin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0)
            dfs(i);
        if (isFind)
            break;
    }
    if (!isFind)
        fout << "NO";
    return 0;
}
