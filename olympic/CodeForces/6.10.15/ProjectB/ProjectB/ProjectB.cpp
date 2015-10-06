// ProjectB.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

const int mod = 1000000007;

int n;
long long *power;

/*long long gen(int count)
{
	if (count == n)
		return 0;
	return (20 * power[n - count - 1] + 7 * gen(count + 1)) % mod;
}*/

int main()
{
	n = 0;
	cin >> n;
	power = new long long[n];
	power[0] = 1;
	for (int i = 1; i < n; i++)
	{
		power[i] = (power[i - 1] * 27) % mod;
	}
	//long long *result = new long long[n + 1];
	long long result = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		result = (20 * power[n - i - 1] + 7 * result) % mod;
	}
	cout << result << endl;
	return 0;
}

