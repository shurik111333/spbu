#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

ifstream fin("area.in");
ofstream fout("area.out");

struct Point
{
	long long x, y;
	
	Point()
	{
		x = y = 0;
	}
	
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
	int n;
	fin >> n;
	Point *p = new Point[n + 1];
	for (int i = 0; i < n; i++)
	{
		int a, b;
		fin >> a >> b;
		p[i].x = a;
		p[i].y = b;
	}
	p[n].x = p[0].x;
	p[n].y = p[0].y;
	double s = 0;
	for (int i = 0; i < n; i++)
	{
		s += p[i + 1] % p[i];
	}
	fout << setprecision(20) << abs(s) / 2;
	return 0;
}
