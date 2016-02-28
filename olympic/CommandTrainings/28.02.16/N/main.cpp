#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, x;
		cin >> n >> x;
		int q = n / 2 + (n % 2);
		if (x <= n && (x % 2) == (q % 2))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}

