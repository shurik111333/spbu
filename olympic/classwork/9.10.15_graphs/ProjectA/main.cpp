#include <iostream>
#include <fstream>

using namespace std;

int first[21000] = {}, next1[410000] = {}, val[410000] = {};
int used[21000] = {};
int countVal = 0;

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

void dfs(int s, int comp)
{
    used[s] = comp;
    int v = first[s];
    while (v != 0)
    {
        if (used[val[v]] == 0)
        {
            dfs(val[v], comp);
        }
        v = next1[v];
    }
}

int main()
{
    ifstream fin("connect.in");
    ofstream fout("connect.out");
    int n, m;
    fin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            result++;
            dfs(i, result);
        }
    }
    fout << result << endl;
    for (int i = 1; i <= n; i++)
    {
        fout << used[i] << " ";
    }
    return 0;
}

