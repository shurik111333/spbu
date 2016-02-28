#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi = acos(-1);

int main()
{
	int n;
	cin >> n;
	double t = 0;
	double s = 0;
	for (int i = 0; i < n; i++)
	{
		int r, v;
		cin >> r >> v;
		s += pi * r;
		t += pi * r / v;
	}
	cout << setprecision(20) << s / t;
	return 0;
}

