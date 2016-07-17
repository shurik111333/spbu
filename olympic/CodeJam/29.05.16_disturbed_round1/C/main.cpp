#include <iostream>
#include <bits/stdc++.h>
#include "message.h"
#include "rps.h"

using namespace std;
typedef long long ll;

#define MASTER 0
const int rend = -1;

const char P = 'P';
const char S = 'S';
const char R = 'R';

//char GetFavoriteMove(int x)
//{
//    return P;
//}

//int GetN()
//{
//    return 28;
//}

int winner(int a, int b)
{
    char c1 = GetFavoriteMove(a);
    char c2 = GetFavoriteMove(b);
    if (c1 == c2)
        return a;
    switch (c1)
    {
    case P:
        return c2 == S ? b : a;
    case R:
        return c2 == P ? b : a;
    case S:
        return c2 == R ? b : a;
    default:
        throw a;
    }
}

int main()
{
    ll n = GetN();
    ll nodes = NumberOfNodes();
    ll myId = MyNodeId();
    ll size = (1 << n);
    assert(size > 0);
    for (int i = myId; i < size; i += nodes)
    {
        PutInt(myId / 2, i);
        PutInt(myId / 2, rend);
        Send(myId / 2);
    }
    int q = 1;
    for (int qq = 1; qq <= n; qq++)
    {
        size >>= 1;
        if ((size) / 2 < myId)
            break;
        int l = myId * 2;
        int r = myId * 2 + 1;
        while (true)
        {
            Receive(l);
            int lx = GetInt(l);
            Receive(r);
            int rx = GetInt(r);
            if (lx == rend && rx == rend)
                break;
            if (lx * rx < 0)
                throw 1;
            int w = winner(lx, rx);
            PutInt(myId / 2, w);
        }
        PutInt(myId / 2, rend);
        Send(myId / 2);
    }
    if (myId == 0)
    {
        Receive(myId);
        int ans = GetInt(myId);
        printf("%lld\n", ans);
    }
    return 0;
}

