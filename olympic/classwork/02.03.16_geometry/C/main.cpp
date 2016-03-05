#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

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

double pi = acos(-1);

int main()
{
	ifstream fin("point1.in");
	ofstream fout("point1.out");
	long long x, y, a, b, c;
	fin >> x >> y >> a >> b >> c;
	if (a * x + b * y == -c)
		fout << "YES";
	else
		fout << "NO";
	return 0;
}
