#pragma once

template <typename Operation>
class SegmentTree
{
private:
    long long *tree;
    long long *delta;
    Operation oper;
    int size;
    int count;

    template <typename T>
    T max(T a, T b)
    {
        return a > b ? a : b;
    }

    void update(int v)
    {
        if (v >= this->count)
            return;
        //this->tree[v] = max(this->tree[v * 2], this->tree[v * 2 + 1]);
        this->tree[v] = oper(this->tree[v * 2], this->tree[v * 2 + 1]);
    }

    void updateResult(long long &result, int v)
    {
        result = max(result, this->tree[v]);
    }

    void push(int v)
    {
        if (this->delta == nullptr || this->delta[v] == 0)
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
        long long result = max(Max(v * 2, l, (r + l) / 2, left, right), Max(v * 2 + 1, (r + l) / 2 + 1, r, left, right));
        update(v);
        return result;
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
        oper = Operation();
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
};
