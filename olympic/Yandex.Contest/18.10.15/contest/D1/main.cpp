#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double min(double a, double b)
{
    return a < b? a : b;
}
int main()
{
    double h1, h2, t1, t2, b, a, c, d, ans;
    cin >> h1 >> t1 >> h2 >> t2;
    b = -h2 * t1 + h1 * t2;
    a = h1 - h2;
    c = h1 * t2 * t2 - h2 * t1 * t1;
    d = b*b - a*c;
    ans = min(abs((b - sqrt(d))/a),abs((b + sqrt(d))/a)) ;
    cout << setprecision(8) << ans;
    return 0;
}

