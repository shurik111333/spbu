#include <iostream>
#include <fstream>
#include <cstring>

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
    ifstream fin("sum.in");
    ofstream fout("sum.out");
    int n = 0, k = 0;
    fin >> n >> k;
    int *values = new int[n];
    for (int i = 0; i < n; i++)
    {
        values[i] = 0;
    }
    SegmentTree rsq = SegmentTree(n, values);
    for (int i = 0; i < k; i++)
    {
        char c;
        int a, b;
        fin >> c >> a >> b;
        if (c == 'A')
            rsq.update(a - 1, b);
        else
            fout << rsq.sum(a - 1, b - 1) << "\n";
    }
    return 0;
}
