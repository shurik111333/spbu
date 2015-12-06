#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge
{
    int a;
    int b;

    Edge()
    {
        a = b = 0;
    }

    Edge(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};

int p[51000] = {};
int r[51000] = {};


double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

/*void qSort(int left, int right, Edge edges[])
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
}*/

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        r[i] = 1;
        p[i] = i;
    }
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
    ifstream fin("cutting.in");
    ofstream fout("cutting.out");
    int n = 0, m = 0, k = 0;
    fin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
    }
    init(n);
    int op[151000] = {};
    Edge edges[151000] = {};
    for (int i = 0; i < k; i++)
    {
        char command[5] = {};
        int a, b;
        fin >> command >> a >> b;
        edges[i] = Edge(a, b);
        op[i] = command[0] - 'a';
    }
    for (int i = k - 1; i >= 0; i--)
    {
        if (op[i] == 0)
        {
            op[i] = parent(edges[i].a) == parent(edges[i].b);
        }
        else
        {
            op[i] = -1;
            if (parent(edges[i].a) != parent(edges[i].b))
                merge(edges[i].a, edges[i].b);
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (op[i] != -1)
        {
            if (op[i] != 0)
                fout << "YES";
            else
                fout << "NO";
            fout << "\n";
        }
    }
    return 0;
}

