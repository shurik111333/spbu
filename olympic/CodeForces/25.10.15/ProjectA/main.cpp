#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int l, p ,q;
    cin >> l >> p >> q;
    double t = l / (p + q);
    double l1 = t * p;
    double l2 = t * q;
    double t1 = l1 / p;
    double l4 = t1 * q;
    double l6 = 0;
    if (l4 > l2)
        l6 = l - (l4 - l2);
    else
        l6 = l + l2 - l4;
    double rest = l6 / (p + q);
    cout << setprecision(15) << rest * p;
    return 0;
}

