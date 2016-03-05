#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

struct Point
{
	long long x, y;
	
	long long operator * (const Point &a)
	{
		return x * a.x + y * a.y;
	}
	
	long long operator % (const Point &a)
	{
		return x * a.y - y * a.x;
	}
};

double pi = acos(-1);

int main()
{
	ifstream fin("angle2.in");
	ofstream fout("angle2.out");
	long long a, b, c, d;
	fin >> a >> b >> c >> d;
	Point p1{a, b};
	Point p2{c, d};
	double res = atan2(p1 % p2, p1 * p2);
	if (res < 0)
		res = -res;
	if (res > pi)
		res = 2 * pi - res;
	fout << setprecision(20) << res;
	return 0;
}

