#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("jealous.in");
	ofstream fout("jealous.out");
	long long a, b;
	fin >> a >> b;
	long long p, q;
	long long sum = 0;
	fin >> p >> q;
	long long znam = p;
	while ((b / znam - (a - 1) / znam) != 0)
	{
		sum += b / znam - (a - 1) / znam;
		znam *= q;
		if (znam < p * q)
			break;
		sum -= b / znam - (a - 1) / znam;
		znam *= p;
		if (znam < p * q)
			break;
	}
	fout << sum;
	return 0;
}