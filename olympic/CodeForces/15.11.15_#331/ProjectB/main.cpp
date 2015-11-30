#include <iostream>

using namespace std;

long long b;

long long Abs(long long a)
{
    return a < 0 ? -a : a;
}

int main()
{
    int n;
    cin >> n;
    long long res = 0;
    long long d = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        res += Abs(b - d);
        d = b;
    }
    cout << res << endl;
    return 0;
}

