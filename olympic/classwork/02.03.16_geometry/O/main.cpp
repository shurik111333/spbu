#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const double pi = acos(-1);

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
	
	double abs()
	{
		return sqrt(x * x + y * y);
	}
};

int main()
{
	ifstream fin("line3.in");
	ofstream fout("line3.out");
	int a, b, c, r;
	fin >> a >> b >> c >> r;
	if (b == 0)
	{
		fout << setprecision(20) << a << " " << b << " " << c - r * a << "\n" << a << " " << b << " " << c + r * a;
		return 0;
	}
	Point n{a, b};
	Point e{0, 1};
	double cosa = (1.0 * (n * e) / n.abs());
	if (cosa < 0)
		cosa = -cosa;
	fout << setprecision(20) << a << " " << b << " " << c - 1.0 * r * b / cosa << "\n";
	fout << setprecision(20) << a << " " << b << " " << c + 1.0 * r * b / cosa;
	return 0;
}
