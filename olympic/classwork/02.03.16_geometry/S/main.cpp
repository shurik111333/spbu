#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

struct Point
{
	double x, y;
	
	bool operator > (const Point &a)
	{
		return (x > a.x || (x == a.x && y > a.y));
	}
	
	bool operator < (const Point &a)
	{
		return (x < a.x || (x == a.x && y < a.y));
	}
	
	bool operator == (const Point &a)
	{
		return x == a.x && y == a.y;
	}
	
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

ifstream fin("goat7.in");
ofstream fout("goat7.out");

int f(Point p1, Point p2, Point p3, Point p4)
{
	if (p3 == p4)
		return 0;
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
	if (p2 == p3)
	{
		return p1 == p2 ? 1 : 0;
	}
	Point v1 = p1 - p2;
	Point v = p3 - p2;
	Point v2 = p1 - p3;
	if ((v1 * v) * (v2 * v) <= 0 && (v1 % v == 0))
		return 1;
	else
		return 0;
}

Point max1(Point a, Point b)
{
	return a > b ? a : b;
}

Point min1(Point a, Point b)
{
	return a < b ? a : b;
}

Point dist(int a1, int b1, int c1, int a2, int b2, int c2)
{
	Point res{1.0 * (b2 * c1 - b1 * c2) / (a2 * b1 - b2 * a1), 1.0 * (c1 * a2 - c2 * a1) / (b2 * a1 - a2 * b1)};
	return res;
}

void print(Point a)
{
	cout << setprecision(20) << a.x << " " << a.y << "\n";
}

bool segmentIntersec(Point p1, Point p2, Point p3, Point p4)
{
	if (f(p1, p2, p3, p4) + f(p3, p4, p1, p2) == 2)
	{
		int a1 = p1.y - p2.y;
		int b1 = p2.x - p1.x;
		int c1 = -a1 * p1.x - b1 * p1.y;
		int a2 = p3.y - p4.y;
		int b2 = p4.x - p3.x;
		int c2 = -a2 * p3.x - b2 * p3.y;
		Point res = dist(a1, b1, c1, a2, b2, c2);
		print(res);
		return true;
	}
	else
	{
		int q = f1(p1, p3, p4) + f1(p2, p3, p4) + f1(p3, p1, p2) + f1(p4, p1, p2);
		if (q > 0)
		{
			if (q == 1)
			{
				/*if (p1 == p3 || p1 == p4)
					print(p1);
				if (p2 == p3 || p2 == p4)
					print(p2);*/
				if (f1(p1, p3, p4) == 1)
				{
					print(p1);
				}
				if (f1(p2, p3, p4) == 1)
				{
					print(p2);
				}
				if (f1(p3, p1, p2) == 1)
				{
					print(p3);
				}
				if (f1(p4, p1, p2) == 1)
				{
					print(p1);
				}
			}
			if (q > 1)
			{
				Point res1 = max1(min1(p1, p2), min1(p3, p4));
				print(res1);
				Point res2 = min1(max1(p1, p2), max1(p3, p4));
				if (!(res1 == res2))
					print(res2);
			}
			return true;
		}
		else
			return false;
	}
}

int main()
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	Point p1{x1, y1};
	Point p2{x2, y2};
	Point p3{x3, y3};
	Point p4{x4, y4};
	if (!segmentIntersec(min1(p1, p2), max1(p1, p2), min1(p3, p4), max1(p3, p4)))
		cout << "Empty";
	return 0;
}
