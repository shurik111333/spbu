#include <iostream>

using namespace std;

int main()
{
    int size = (1 << 27);
    int ans = 0;
    while (size > 1)
    {
        ans += size / 100 + 1;
        size >>= 1;
    }
    cout << ans << endl;
    return 0;
}

