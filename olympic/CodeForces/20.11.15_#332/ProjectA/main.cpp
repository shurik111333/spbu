#include <iostream>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << min((a + b) * 2, min(a + b + c, 2 * c + 2 * min(a, b)));
    return 0;
}
