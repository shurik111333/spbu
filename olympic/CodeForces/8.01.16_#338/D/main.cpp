#include <iostream>
#include <cassert>

using namespace std;

int p[210000] = {};
int mod = 1000000000 + 7;
int fmod = mod - 1;

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
        this->tree[i] = (this->tree[i * 2] * this->tree[i * 2 + 1]) % fmod;
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
                tree[i] = values[i - this->count] + 1;
            else
                tree[i] = 1;
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
        long long result = 1;
        while (l <= r)
        {
            if (l % 2 == 1)
            {
                result = (result * this->tree[l]) % fmod;
                l++;
            }
            if (r % 2 == 0)
            {
                result = (result * this->tree[r]) % fmod;
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return result % fmod;
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

long long pow1(long long a, long long b)
{
	if (b == 0)
		return 1;
	if ((b % 2) == 1)
	{
		return (a * pow1(a, b - 1)) % mod;
	}
	else
	{
		long long tmp = pow1(a, b / 2);
		return (tmp * tmp) % mod;
	}
}

int main()
{
	int m = 0;
	int p1 = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> p1;
		p[p1]++;
	}
	SegmentTree tree(201001, p);
	long long res1 = 1;
	for (int i = 2; i <= 200000; i++)
	{
		if (p[i] > 0)
		{
			long long currPow = tree.sum(0, i - 1);
			currPow = (currPow * tree.sum(i + 1, 200001)) % fmod;
			long long tmp = pow1(i, ((currPow * ((((1ll * p[i] + 1) * p[i]) / 2) % fmod)) % fmod));
			res1 = (res1 * tmp) % mod;
		}
	}
	cout << res1;
	return 0;
}
