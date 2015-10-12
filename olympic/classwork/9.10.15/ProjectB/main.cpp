#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int first[101000] = {}, next1[101000] = {}, val[101000] = {}, d[101000] = {};
int used[101000] = {};
int countVal = 0;
int n;

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

void bfs(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = -1;
    }
    d[s] = 0;
    queue<int> vertex;
    vertex.push(s);
    while (!vertex.empty())
    {
        int currV = vertex.front();
        vertex.pop();
        int v = first[currV];
        while (v != 0)
        {
            if (d[val[v]] == -1)
            {
                vertex.push(val[v]);
                d[val[v]] = d[currV] + 1;
            }
            v = next1[v];
        }
    }
}

int main()
{
    //ifstream fin("bfsrev.in");
    //ofstream fout("bfsrev.out");
    freopen("bfsrev.in", "r", stdin);
    freopen("bfsrev.out", "w", stdout);
    int m, s;
    scanf("%d%d%d", &n, &s, &m);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        //fin >> a >> b;
        scanf("%d%d", &a, &b);
        add(b, a);
    }
    bfs(s);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", d[i]);
    }
    return 0;
}
