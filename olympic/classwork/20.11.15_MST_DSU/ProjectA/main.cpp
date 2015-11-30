#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge
{
    int a;
    int b;
    double weight;

    Edge()
    {
        a = b = weight = 0;
    }

    Edge(int a, int b, double weight)
    {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
};

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

Edge *prim(int n, int m, Edge *edges)
{
    Edge *minTree = new Edge[n - 1];
    bool *isUsed = new bool[n];
    memset(isUsed, false, n);
    isUsed[0] = true;
    for (int i = 0; i < n - 1; i++)
    {
        int minEdgeIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (isUsed[edges[j].a] ^ isUsed[edges[j].b] && (minEdgeIndex == -1 || edges[j].weight < edges[minEdgeIndex].weight))
            {
                minEdgeIndex = j;
            }
        }
        if (minEdgeIndex == -1)
        {
            delete[] minTree;
            minTree = nullptr;
            break;
        }
        minTree[i] = edges[minEdgeIndex];
        isUsed[minTree[i].a] = isUsed[minTree[i].b] = true;
    }
    delete[] isUsed;
    return minTree;
}

int main()
{
    ifstream fin("connect.in");
    ofstream fout("connect.out");
    int n = 0;
    fin >> n;
    Edge *edges = new Edge[n*n + 1];
    int *x = new int[n], *y = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> x[i] >> y[i];
        //edges[i] = Edge(a - 1, b - 1, c);
    }
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges[count++] = Edge(i, j, dist(x[i], y[i], x[j], y[j]));
        }
    }
    Edge *minTree = prim(n, count, edges);
    delete[] edges;
    double len = 0;
    for (int i = 0; i < n - 1; i++)
    {
        len += minTree[i].weight;
    }
    fout << setprecision(15) << len << endl << n - 1 << endl;
    for (int i = 0; i < n - 1; i++)
    {
        fout << minTree[i].a + 1 << " " << minTree[i].b + 1 << "\n";
    }
    delete[] minTree;
    return 0;
}
