#include <iostream>
#include <fstream>

using namespace std;

long long n = 0, k = 0;
int res[20] = {};
int a[20] = {};
long long pow10[12] = {};
int currIndex = 1;
bool p[200000] = {};
//int g[30] = {};

void case1(int maxN)
{
    while (true)
    {
        long long count = 0;
        for (int i = 0; i <= maxN - currIndex; i++)
        {
            count += pow10[i];
        }
        res[currIndex] += k / count;
        k %= count;
        currIndex++;
        if (k == 0)
        {
            //res[currIndex] = -1;
            return;
        }
        k--;
    }
}

void case2(int maxN, int count)
{
    //while (true)
    {
        //long long count = 0;
        /*int count = 0;
        for (int i = 0; i <= maxN - currIndex; i++)
        {
            count += pow10[i];
        }
        count -= pow10[maxN - currIndex - 1] * res[currIndex];*/
        //int count = g[currIndex + 1];
        res[currIndex] += k / count + 1;
        k %= count;
        currIndex++;
        if (k == 0)
        {
            //res[currIndex] = -1;
            return;
        }
        k--;
        case1(maxN);
    }
}

int main()
{
    ifstream fin("lexsort.in");
    ofstream fout("lexsort.out");
    fin >> n >> k;
    if (k == 0)
    {
        fout << 0;
        return 0;
    }
    k--;

    pow10[0] = 1;
    for (int i = 1; i < 12; i++)
    {
        pow10[i] = pow10[i - 1] * 10;
    }

    int maxCount = 0;
    int n1 = n;
    while (n1 > 0)
    {
        maxCount++;
        n1 /= 10;
    }
    n1 = n;

    for (int i = maxCount; i > 0; i--)
    {
        a[i] = n1 % 10;
        n1 /= 10;
    }
    int g1 = 0;
    for (int i = 0; i < maxCount; i++)
    {
        g1 += (a[1] - 1) * pow10[i];
    }
    int g2 = 0;
    for (int i = 2; i <= maxCount; i++)
    {
        g2 += (a[i]) * (pow10[maxCount - i]);
    }
    int gt = g2;
    do
    {
        gt /= 10;
        g2 += gt + 1;
    }
    while (gt > 0);
    g2++;
    g1 += g2;
    if (k < g1)
    {
        int count = 0;
        for (int i = 0; i < maxCount; i++)
        {
            count += pow10[i];
        }
        res[currIndex] = (k / count) + 1;
        currIndex++;
        k %= count;
        if (k != 0)
        {
            k--;
            case1(maxCount);
        }
    }
    else
    {
        k -= g1;
        maxCount--;
        k += ((pow10[maxCount] - 1) - n + g1);
        int count = 0;

        for (int i = 0; i < maxCount; i++)
        {
            count += pow10[i];
        }
        res[currIndex] = (k / count) + 1;
        currIndex++;
        k %= count;
        if (k != 0)
        {
            k--;
            case1(maxCount);
        }
    }
    for (int i = 1; i < currIndex; i++)
    {
        fout << res[i];
    }
    return 0;
}

