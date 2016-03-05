#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin("angle1.in");
	ofstream fout("angle1.out");
	int a, b;
	fin >> a >> b;
	double res = atan2(b, a);
	if (res < 0)
		res += 2 * acos(-1);
	fout << setprecision(20) << res;
	return 0;
}

