#include <iostream>
#include <fstream>

using namespace std;

class SegmentTree
{
private:
    long long *tree;
    int size;
    int count;

    void update(int i)
    {
        if (i >= this->count)
            return;
        this->tree[i] = this->tree[i * 2] + this->tree[i * 2 + 1];
    }

public:

    SegmentTree(int count, int *values)
    {
        this->count = 1;
        while (this->count < count)
        {
            this->count *= 2;
        }
        size = this->count * 2;
        tree = new long long[size + 1];
        for (int i = this->count; i < size; i++)
        {
            if (i - this->count < count)
                tree[i] = values[i - this->count];
            else
                tree[i] = 0;
        }
        for (int i = this->count - 1; i > 0; i--)
        {
            update(i);
        }
    }

    long long sum(int left, int right)
    {
        int l = left + this->count;
        int r = right + this->count;
        long long result = 0;
        while (l <= r)
        {
            if (l % 2 == 1)
            {
                result += this->tree[l];
                l++;
            }
            if (r % 2 == 0)
            {
                result += this->tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return result;
    }

    void update(int ind, int x)
    {
        this->tree[ind + this->count] = x;
        for (int i = (ind + this->count) / 2; i > 0; i /= 2)
        {
            update(i);
        }
    }
};

int main()
{
    ifstream fin("signchange.in");
    ofstream fout("signchange.out");
    int n, k;
    fin >> n;
    int *values = new int[n + 1];
    int *v1 = new int[n + 1];
    int *v2 = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        fin >> values[i];
        v1[i] = 0;
        v2[i] = 0;
        if (i % 2 == 0)
        {
            v2[i] = values[i];
        }
        else
            v1[i] = values[i];
    }
    SegmentTree rsq1 = SegmentTree(n, v1);
    SegmentTree rsq2 = SegmentTree(n, v2);
    fin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, a, b;
        fin >> x >> a >> b;
        if (x == 0)
        {
            if (((a - 1) % 2) == 0)
                rsq2.update(a - 1, b);
            else
                rsq1.update(a - 1, b);
        }
        else
        {
            long long result = rsq2.sum(a - 1, b - 1) - rsq1.sum(a - 1, b - 1);
            if ((a - 1) % 2 == 1)
                result = -result;
            fout << result << "\n";
        }
    }
    return 0;
}

