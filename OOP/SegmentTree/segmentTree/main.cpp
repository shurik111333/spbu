#include <iostream>
#include "segmenttree.h"
#include <set>

using namespace std;

struct _sum
{
    int operator()(const long long &a, long long &b)
    {
        return a < b ? a : b;
    }
};

struct _less
{
    bool operator ()(int a, int b)
    {
        return a < b ? a : b;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    int *v = new int[8];
    for (int i = 0; i < 8; i++)
    {
        v[i] = i;
    }
    SegmentTree<_sum> rsq = SegmentTree<_sum>(8, v);
    return 0;
}

