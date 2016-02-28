#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		bool res1 = false;
		bool res2 = false;
		if (a + b + c > d + e + f)
			res1 = true;
		if (a > d || (a == d && b > e) || (a == d && b == e && c > f))
			res2 = true;
		if (res1 && res2)
		{
			cout << "Win" << "\n";
			continue;
		}
		if (res1)
		{
			cout << "Count" << "\n";
			continue;
		}
		if (res2)
		{
			cout << "Quality" << "\n";
			continue;
		}
		cout << "None" << "\n";
	}
	return 0;
}

