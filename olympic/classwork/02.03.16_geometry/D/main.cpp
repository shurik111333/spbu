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
	ifstream fin("point2.in");
	ofstream fout("point2.out");
	int x, y, a, b, c, d;
	fin >> x >> y >> a >> b >> c >> d;
	Point p{x - a, y - b};
	Point n{c - a, d - b};
	if (p % n == 0 && p * n >= 0)
		fout << "YES";
	else
		fout << "NO";
	return 0;
}

