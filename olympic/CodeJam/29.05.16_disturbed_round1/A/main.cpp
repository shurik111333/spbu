#include <iostream>
#include <bits/stdc++.h>
#include "message.h"
#include "oops.h"

using namespace std;
typedef long long ll;

int main()
{
    ll n = GetN();
    ll nodes = NumberOfNodes();
    ll myNode = MyNodeId();
    ll max1 = GetNumber(0);
    ll min1 = GetNumber(myNode);
    ll k = myNode + nodes;
    for (int i = 1; i < n; i++)
    {
        ll x = GetNumber(i);
        if (x > max1)
            max1 = x;
        if (i == k)
        {
            k += nodes;
            if (x < min1)
                min1 = x;
        }
    }
    if (myNode == nodes - 1)
    {
        ll ans = max1 - min1;
        for (int i = 0; i < nodes - 1; i++)
        {
            Receive(i);
            ll x = GetLL(i);
            if (x > ans)
                ans = x;
        }
        printf("%lld\n", ans);
    }
    else
    {
        PutLL(nodes - 1, max1 - min1);
        Send(nodes - 1);
    }
    return 0;
}

