#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

class SegmentTree
{
private:
    long long *tree;
    long long *delta;
    int size;
    int count;

    template <typename T>
    T min(T a, T b)
    {
        return a < b ? a : b;
    }

    template <typename T>
    T max(T a, T b)
    {
        return a > b ? a : b;
    }

    void update(int v)
    {
        if (v >= this->count)
            return;
        this->tree[v] = min(this->tree[v * 2], this->tree[v * 2 + 1]);
    }

    void updateResult(long long &result, int v)
    {
        result = min(result, this->tree[v]);
    }

    void push(int v)
    {
        if (this->delta[v] == 0)
            return;
        this->tree[v] += this->delta[v];
        if (v < this->count)
        {
            this->delta[v * 2] += this->delta[v];
            this->delta[v * 2 + 1] += this->delta[v];
        }
        this->delta[v] = 0;
    }

    void update(int v, int l, int r, int left, int right, int d)
    {
        push(v);
        if (r < left || l > right)
            return;
        if (l >= left && r <= right)
        {
            this->delta[v] += d;
            push(v);
            return;
        }
        update(v * 2, l, (r + l) / 2, left, right, d);
        update(v * 2 + 1, (r + l) / 2 + 1, r, left, right, d);
        update(v);
    }

    long long Max(int v, int l, int r, int left, int right)
    {
        push(v);
        if (r < left || l > right)
            return INT_MIN;
        if (l >= left && r <= right)
        {
            return this->tree[v];
        }
        long long result = min(Max(v * 2, l, (r + l) / 2, left, right), Max(v * 2 + 1, (r + l) / 2 + 1, r, left, right));
        update(v);
        return result;
    }

    void countL(int v, int l, int r, long long &left, int p, int x)
    {
        if (l >= left || r < left - 1)
            return;
        if (this->tree[v] > x)
        {
            left = l;
            return;
        }
        if (r == l)
            return;
        countL(v * 2 + 1, (r + l) / 2 + 1, r, left, p, x);
        countL(v * 2, l, (r + l) / 2, left, p, x);
    }

    void countR(int v, int l, int r, int p, long long &right, int x)
    {
        if (r <= right || l > right + 1)
            return;
        if (this->tree[v] >= x)
        {
            right = r;
            return;
        }
        if (l == r)
            return;
        countR(v * 2, l, (r + l) / 2, p, right, x);
        countR(v * 2 + 1, (r + l) / 2 + 1, r, p, right, x);
    }

public:

    SegmentTree(int count, long long *values)
    {
        this->count = 1;
        while (this->count < count)
        {
            this->count *= 2;
        }
        size = this->count * 2;
        tree = new long long[size + 1];
        delta = new long long[size + 1];
        for (int i = this->count; i < size; i++)
        {
            delta[i] = 0;
            if (i - this->count < count)
                tree[i] = values[i - this->count];
            else
                tree[i] = INT_MIN;
        }
        for (int i = this->count - 1; i > 0; i--)
        {
            delta[i] = 0;
            update(i);
        }
    }

    long long Max(int left, int right)
    {
        return Max(1, 0, this->count - 1, left, right);
    }

    void update(int left, int right, int d)
    {
        update(1, 0, this->count - 1, left, right, d);
    }

    void countL(int v, long long &left)
    {
        countL(1, 0, this->count - 1, left, v, this->tree[v + this->count]);
    }

    void countR(int v, long long &right)
    {
        countR(1, 0, this->count - 1, v, right, this->tree[v + this->count]);
    }
};

int main()
{
    ifstream fin("minsum.in");
    ofstream fout("minsum.out");
    int n = 0;
    fin >> n;
    long long *values = new long long[n];
    for (int i = 0; i < n; i++)
    {
        fin >> values[i];
    }
    SegmentTree rmq = SegmentTree(n, values);
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        long long l = i;
        rmq.countL(i, l);
        long long r = i;
        rmq.countR(i, r);
        result += values[i] * ((r - i + 1) * (i - l + 1));
    }
    fout << result;
    return 0;
}
