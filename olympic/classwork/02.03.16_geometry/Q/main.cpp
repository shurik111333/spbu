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

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

Point dist(int a1, int b1, int c1, int a2, int b2, int c2)
{
	Point res{1.0 * (b2 * c1 - b1 * c2) / (a2 * b1 - b2 * a1), 1.0 * (c1 * a2 - c2 * a1) / (b2 * a1 - a2 * b1)};
	return res;
}

double dist1(int x1, int y1, int x2, int y2, int x3, int y3)
{
	Point p1{x2 - x1, y2 - y1};
	Point p2{x3 - x1, y3 - y1};
	Point p3{x3 - x2, y3 - y2};
	if (p1 * p3 < 0)
		return (1.0 * abs((p1 % p2))) / (dist(x2, y2, x3, y3));
	else
		return dist(x1, y1, x2, y2);
}

double eps = 10e-8;

double min1(double a, double b)
{
	return a < b ? a : b;
}

int main()
{
	ifstream fin("raydist.in");
	ofstream fout("raydist.out");
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	Point p;
	double res = 0;
	int a1 = y1 - y2;
	int b1 = x2 - x1;
	int c1 = -a1 * x1 - b1 * y1;
	int a2 = y3 - y4;
	int b2 = x4 - x3;
	int c2 = -a2 * x3 - b2 * y3;
	if (a2 * b1 - b2 * a1 != 0)
	{
		p = dist(a1, b1, c1, a2, b2, c2);
		Point v1{x2 - x1, y2 - y1};
		Point v2{x4 - x3, y4 - y3};
		Point v3{p.x - x1, p.y - y1};
		Point v4{p.x - x3, p.y - y3};
		if (v1 * v3 > 0 && v2 * v4 > 0)
		{
			res = 0;
		}
		else
			res = min1(dist1(x1, y1, x3, y3, x4, y4), dist1(x3, y3, x1, y1, x2, y2));
	}
	else
		res = min1(dist1(x1, y1, x3, y3, x4, y4), dist1(x3, y3, x1, y1, x2, y2));
	if (abs(res) < eps)
		res = 0;
	cout << setprecision(20) << res;
	fout.close();
	fin.close();
	return 0;
}
