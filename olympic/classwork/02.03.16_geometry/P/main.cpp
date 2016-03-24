#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const double pi = acos(-1);

struct Point
{
	double x, y;
	
	double operator *(const Point &a)
	{
		return x * a.x + y * a.y;
	}
	
	double operator % (const Point &a)
	{
		return x * a.y - y * a.x;
	}
	
	double abs()
	{
		return sqrt(x * x + y * y);
	}
	
	void normalize()
	{
		double a = abs();
		x = x / a;
		y = y / a;
	}
};

int main()
{
	ifstream fin("bisector.in");
	ofstream fout("bisector.out");
	int x1, y1, x2, y2, x3, y3;
	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point y{x2 - x1, y2 - y1};
	Point z{x3 - x1, y3 - y1};
	y.normalize();
	z.normalize();
	Point c{(y.x + z.x) / 2 + x1, (y.y + z.y) / 2 + y1};
	double a = c.y - y1;
	double b = x1 - c.x;
	fout << setprecision(20) << a << " " << b << " " << -a * x1 - b * y1;
	return 0;
}
