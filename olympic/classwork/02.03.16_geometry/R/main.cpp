#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Point
{
	long long x, y;
	
	long long operator *(const Point &a)
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
	ifstream fin("area1.in");
	ofstream fout("area1.out");
	int x1, y1, x2, y2, x3, y3;
	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point p1{x1 - x2, y1 - y2};
	Point p2{x3 - x2, y3 - y2};
	fout << setprecision(20) << 1.0 * abs((p1 % p2)) / 2;
	return 0;
}
