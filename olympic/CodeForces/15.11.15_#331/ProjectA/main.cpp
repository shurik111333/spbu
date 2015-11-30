#include <iostream>

using namespace std;

int abs(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    int n = 0;
    cin >> n;
    if (n == 1)
    {
        cout << -1;
        return 0;
    }
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    if (x0 != x1 && y0 != y1)
    {
        cout << (abs(x0 - x1) * abs(y0 - y1));
        return 0;
    }
    if (n == 2)
    {
        cout << -1;
        return 0;
    }
    int a = abs(x0 - x1) + abs(y0 - y1);
    cin >> x1 >> y1;
    if (x0 != x1 && y0 != y1)
    {
        cout << (abs(x0 - x1) * abs(y0 - y1));
        return 0;
    }
    int b = abs(x0 - x1) + abs(y0 - y1);
    cout << a * b;
    return 0;
}

