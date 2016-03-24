#include <iostream>
#include <fstream>

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
	
	Point operator - (const Point &a)
	{
		return Point{x - a.x, y - a.y};
	}
};

int f(Point p1, Point p2, Point p3, Point p4)
{
	Point v1 = p1 - p3;
	Point v2 = p2 - p3;
	Point v3 = p4 - p3;
	if (((v1 % v3) < 0 && (v2 % v3) > 0) || ((v1 % v3) > 0 && (v2 % v3) < 0))
		return 1;
	else 
		return 0;
}

int f1(Point p1, Point p2, Point p3)
{
	Point v1 = p1 - p2;
	Point v = p3 - p2;
	Point v2 = p1 - p3;
	if ((v1 * v) * (v2 * v) <= 0 && (v1 % v == 0))
		return 1;
	else
		return 0;
}

int main()
{
	ifstream fin("intersec2.in");
	ofstream fout("intersec2.out");
	int x1, y1, x2, y2, x3, y3, x4, y4;
	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	Point p1{x1, y1};
	Point p2{x2, y2};
	Point p3{x3, y3};
	Point p4{x4, y4};
	if (f(p1, p2,  p3, p4) + f(p3, p4, p1, p2) == 2)
		fout << "YES";
	else
	{
		if (f1(p1, p3, p4) + f1(p2, p3, p4) + f1(p3, p1, p2) + f1(p4, p1, p2) > 0)
			fout << "YES";
		else
			fout << "NO";
	}
	return 0;
}
