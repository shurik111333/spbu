#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

struct Point
{
	double x, y;
	
	double operator * (const Point &a)
	{
		return x * a.x + y * a.y;
	}
	
	double operator % (const Point &a)
	{
		return x * a.y - y * a.x;
	}
};

int main()
{
	ifstream fin("position.in");
	ofstream fout("position.out");
	int x1, y1, x2, y2, a, b, c;
	fin >> x1 >> y1 >> x2 >> y2 >> a >> b >> c;
	if (b == 0)
	{
		if ((x1 + 1.0 * c / a) * (x2 + 1.0 * c / a) >= 0)
			fout << "YES";
		else
			fout << "NO";
		return 0;
	}
	Point p1{x1, y1 + 1.0 * c / b};
	Point p2{x2, y2 + 1.0 * c / b};
	Point n{a, b};
	if (((p1 * n) >= 0 && (p2 * n) >= 0) || (p1 * n < 0 && p2 * n < 0))
		fout << "YES";
	else
		fout << "NO";
	return 0;
}
