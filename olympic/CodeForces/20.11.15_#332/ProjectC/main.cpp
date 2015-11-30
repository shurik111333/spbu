#include <iostream>
#include <set>

using namespace std;

struct El
{
    int value;
    int index;

    El()
    {
        value = index = 0;
    }

    El(int a, int b)
    {
        value = a;
        index = b;
    }

    bool operator ==(const El &e)
    {
        return this->value == e.value;
    }

    bool operator <(const El &e) const
    {
        return this->value < e.value || (this->value == e.value && this->index < e.index);
    }
};

El a[110000] = {};
El b[110000] = {};

void qSort(int left, int right, El edges[])
{
    int l = left;
    int r = right;
    El cmp = edges[(l + r) / 2];
    while (l < r)
    {
        while (edges[l] < cmp)
            l++;
        while (cmp < edges[r])
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

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a1;
        cin >> a1;
        a[i] = El(a1, i);
        b[i] = a[i];
    }
    qSort(0, n - 1, b);
    //set<El> s;
    for (int i = 0; i < n; i++)
    {
        a[b[i].index].index = i;
    }
    int ans = 0;
    //int l = 0;
    int r = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].index > r)
        {
            count += a[i].index - r;
            r = a[i].index;
        }
        count--;
        if (count == 0)
        {
            ans++;
            r = i;
        }
    }
    cout << ans;
    return 0;
}

