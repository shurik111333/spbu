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

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	ifstream fin("distance4.in");
	ofstream fout("distance4.out");
	int x1, y1, x2, y2, x3, y3;
	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point p1{x2 - x1, y2 - y1};
	Point p2{x3 - x1, y3 - y1};
	Point p3{x3 - x2, y3 - y2};
	Point p4{x2 - x3, y2 - y3};
	double res = 0;
	if (p1 * p3 < 0 && p2 * p4 < 0)
		res = (1.0 * abs((p1 % p2))) / (dist(x2, y2, x3, y3));
	else
		res = min(dist(x1, y1, x2, y2), dist(x1, y1, x3, y3));
	fout << setprecision(20) << res;
	return 0;
}
