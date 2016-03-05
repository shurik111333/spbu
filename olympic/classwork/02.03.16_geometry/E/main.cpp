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

int main()
{
	ifstream fin("point3.in");
	ofstream fout("point3.out");
	int x, y, a, b, c, d;
	fin >> x >> y >> a >> b >> c >> d;
	Point p{x - a, y - b};
	Point p1{x - c, y - d};
	Point n{c - a, d - b};
	Point n1{a - c, b - d};
	if (p % n == 0 && p * n >= 0 && p1 * n1 >= 0)
		fout << "YES";
	else
		fout << "NO";
	return 0;
}
