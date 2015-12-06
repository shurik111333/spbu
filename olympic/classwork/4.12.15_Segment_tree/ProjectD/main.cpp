#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

unsigned int curr = 0;

unsigned int getNext(long long a, long long b)
{
    curr = curr * a + b;
    return curr >> 8;
}

class RSQ
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

    RSQ(int count, int *values)
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

    RSQ(int count)
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
                tree[i] = 1;
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

class RMQ
{
private:
    long long *tree;
    int *index;
    int size;
    int count;

    template <typename T>
    T min(T a, T b)
    {
        return a < b ? a : b;
    }

    void update(int i)
    {
        if (i >= this->count)
            return;
        this->tree[i] = min(this->tree[i * 2], this->tree[i * 2 + 1]);
        if (this->tree[i * 2] <= this->tree[i * 2 + 1])
            index[i] = index[i * 2];
        else
            index[i] = index[i * 2 + 1];
    }

public:

    RMQ(int count, int *values)
    {
        this->count = 1;
        while (this->count < count)
        {
            this->count *= 2;
        }
        size = this->count * 2;
        tree = new long long[size + 1];
        index = new int[size + 1];
        for (int i = this->count; i < size; i++)
        {
            if (i - this->count < count)
                tree[i] = values[i - this->count];
            else
                tree[i] = INT_MAX;
            index[i] = i - this->count;
        }
        for (int i = this->count - 1; i > 0; i--)
        {
            update(i);
        }
    }

    /*long long sum(int left, int right)
    {
        int l = left + this->count;
        int r = right + this->count;
        long long result = INT_MAX;
        int ind = 0;
        while (l <= r)
        {
            if (l % 2 == 1)
            {
                result = min(this->tree[l], result);
                l++;
            }
            if (r % 2 == 0)
            {
                result = min(this->tree[r], result);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return result;
    }*/

    int getMinIndex()
    {
        return this->index[1];
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
    ifstream fin("invcnt.in");
    ofstream fout("invcnt.out");
    int n = 0, m = 0, a = 0, b = 0;
    fin >> n >> m >> a >> b;
    int *x = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        x[i] = getNext(a, b) % m;
    }
    RMQ rmq = RMQ(n, x);
    RSQ rsq = RSQ(n);
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        int min1 = rmq.getMinIndex();
        result += rsq.sum(0, min1 - 1);
        rmq.update(min1, INT_MAX);
        rsq.update(min1, 0);
    }
    fout << result;
    return 0;
}

