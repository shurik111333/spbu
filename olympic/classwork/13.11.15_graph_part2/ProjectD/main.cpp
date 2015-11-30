#include <iostream>
#include <fstream>
#include <ctime>

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
        :a(a), b(b)
    {
    }

    Edge(Edge &edge)
        :a(edge.a), b(edge.b)
    {
    }

    bool operator <(const Edge &edge)
    {
        return (this->a < edge.a || (this->a == edge.a && this->b < edge.b));
    }

    bool operator ==(const Edge &edge)
    {
        return (this->a == edge.a && this->b == edge.b);
    }
};

int first[110000] = {}, next1[210000] = {}, val[210000] = {}, used[110000] = {};
int topSort[110000] = {};
int first_rev[110000] = {}, next1_rev[210000] = {}, val_rev[210000] = {}, cond[110000] = {};
Edge edges[110000] = {};
int countVal = 0;
int countVal_rev = 0;
ofstream fout("condense2.out");

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

void add_rev(int a, int b)
{
    countVal_rev++;
    val_rev[countVal_rev] = b;
    if (first_rev[a] == 0)
    {
        first_rev[a] = countVal_rev;
        return;
    }
    next1_rev[countVal_rev] = first_rev[a];
    first_rev[a] = countVal_rev;
}


void dfs(int v)
{
    used[v] = 1;
    int k = first[v];
    while (k != 0)
    {
        if (used[val[k]] == 0)
            dfs(val[k]);
        k = next1[k];
    }
    used[v] = 2;
    topSort[++topSort[0]] = v;
}

void dfs(int v, int &color)
{
    cond[v] = -1;
    int k = first_rev[v];
    while (k != 0)
    {
        if (cond[val_rev[k]] == 0)
        {
            dfs(val_rev[k], color);
        }
        k = next1_rev[k];
    }
    cond[v] = color;
}

/*void dfs1(int v)
{
    used[v] = 1;
    int k = first[v];
    while (k != 0)
    {
        if (used[val[k]] == 0)
            dfs1(val[k]);
        k = next1[k];
    }
    k = first_rev[v];
    while (k != 0)
    {
        if (used[val_rev[k]] == 0)
            dfs1(val_rev[k]);
        k = next1_rev[k];
    }
}*/

void swap(Edge &edge1, Edge &edge2)
{
    Edge tmp = edge1;
    edge1 = edge2;
    edge2 = tmp;
}

void qSort(int left, int right)
{
    int l = left;
    int r = right;
    Edge med = edges[(r + l) / 2];
    while (l < r)
    {
        while (edges[l] < med)
            l++;
        while (med < edges[r])
            r--;
        if (l <= r)
        {
            swap(edges[l], edges[r]);
            l++;
            r--;
        }
    }
    if (l < right)
        qSort(l, right);
    if (left < r)
        qSort(left, r);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    ifstream fin("condense2.in");
    int n = 0, m = 0;
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        fin >> a >> b;
        if (a != b)
        {
            add(a, b);
            add_rev(b, a);
        }
    }
    /*srand(time(0));
    while (true)
    {
        n = rand() % 10;
        m = rand() % 15;
        for (int i = 0; i <= max(n, m); i++)
        {
            next1[i] = next1_rev[i] = 0;
            val[i] = val_rev[i] = 0;
            first[i] = first_rev[i] = 0;
            countVal = countVal_rev = 0;
            used[i] = 0;
            topSort[0] = 0;
            cond[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int a = rand() % n + 1, b = rand() % n + 1;
            //fin >> a >> b;
            if (a != b)
            {
                add(a, b);
                add_rev(b, a);
            }
        }*/

    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0)
            dfs(i);
    }
    int color = 1;
    for (int i = n; i > 0; i--)
    {
        if (cond[topSort[i]] == 0)
        {
            dfs(topSort[i], color);
            color++;
        }
    }
    //int res1 = color - 2;
    /*for (int i = 1; i <= n; i++)
    {
        used[i] = 0;
    }
    int count1 = 0;
    for (int i = 1; i<= n; i++)
    {
        if (used[i] == 0)
        {
            dfs1(i);
            count1++;
        }
    }
    res1 -= count1 - 1;*/
    int count = 0;
    //int res = 0;
    for (int i = 1; i <= n; i++)
    //for (int i = n; i > 0; i--)
    {
        int k = first[i];
        while (k != 0)
        {
            if (cond[i] != cond[val[k]])
            {
                edges[count++] = Edge(cond[i], cond[val[k]]);
            }
            k = next1[k];
        }

        /*k = first[i];
        while (k != 0)
        {
            used[val[k]] = 0;
            k = next1[k];
        }*/
    }
    qSort(0, count - 1);
    int res = count;
    for (int i = 0; i < count - 1; i++)
    {
        if (edges[i] == edges[i + 1])
            res--;
    }
    /*if (res != res1)
    {
        fout << res << " " << res1 << endl;
        fout << n << " " << m << endl;
        for (int i = 1; i <= n; i++)
        {
            fout << i << ": ";
            int k = first[i];
            while (k != 0)
            {
                fout << val[k] << " ";
                k = next1[k];
            }
            fout << endl;
        }
        break;
    }
    }*/
    fout << res;
    return 0;
}
