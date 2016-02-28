#include <iostream>

using namespace std;

int abs(int a)
{
	return a < 0 ? -a : a;
}

bool isCorrect(int n)
{
	bool res = true;
	int p = n % 10;
	int q;
	n /= 10;
	while (n > 0 && res)
	{
		q = n % 10;
		res = abs(p - q) == 1;
		p = q;
		n /= 10;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int i = 0;
	int c = 0;
	while (c < n)
	{
		i++;
		if (isCorrect(i))
			c++;
	}
	cout << i;
	return 0;
}

