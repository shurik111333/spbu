#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    int res = max(0, a - x) / 2 + max(0, b - y) / 2 + max(0, c - z) / 2;
    if (res >= max(0,x - a) + max(0, y - b) + max(0, z - c))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
