#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge
{
    int a;
    int b;
    int weight;

    Edge()
    {
        a = b = weight = 0;
    }

    Edge(int a, int b, int weight)
    {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
};

int p[21000] = {};
int r[21000] = {};


double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void qSort(int left, int right, Edge edges[])
{
    int l = left;
    int r = right;
    int cmp = edges[(l + r) / 2].weight;
    while (l < r)
    {
        while (edges[l].weight < cmp)
            l++;
        while (edges[r].weight > cmp)
            r--;
        if (l <= r)
        {
            swap(edges[l], edges[r]);
            l++;
            r--;
        }
    }
    if (l < right)
        qSort(l, right, edges);
    if (left < r)
        qSort(left, r, edges);
}

int parent(int v)
{
    if (p[v] == v)
        return v;
    p[v] = parent(p[v]);
    return p[v];
}

void merge(int v, int u)
{
    v = parent(v);
    u = parent(u);
    if (r[v] < r[u])
        p[v] = u;
    else
    {
        p[u] = v;
        if (r[v] == r[u])
            r[u]++;
    }
}

int main()
{
    ifstream fin("spantree2.in");
    ofstream fout("spantree2.out");
    int n = 0, m = 0;
    fin >> n >> m;
    //int *x = new int[n], *y = new int[n];
    Edge *edges = new Edge[m];
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, c = 0;
        fin >> a >> b >> c;
        edges[i] = Edge(a, b, c);
    }
    //int count = 0;
    /*for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges[count++] = Edge(i, j, dist(x[i], y[i], x[j], y[j]));
        }
    }*/
    qSort(0, m - 1, edges);
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        if (parent(edges[i].a) != parent(edges[i].b))
        {
            result += edges[i].weight;
            merge(edges[i].a, edges[i].b);
        }
    }
    fout << result;
    return 0;
}

