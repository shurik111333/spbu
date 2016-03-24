#include <iostream>
#include <fstream>

using namespace std;

typedef long long ll;

struct Point
{
	int x;
	int y;
};

ll dist(const Point &a, const Point &b)
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct Triangle
{
	Point a;
	Point b;
	Point c;
	int index;
	ll st1;
	ll st2;
	ll st3;

	Triangle():
	    index(0)
	{}

	Triangle(const Point a, const Point b, const Point c, int i):
	    a(a),
	    b(b),
	    c(c),
	    index(i)
	{
		st1 = min(dist(a, b), min(dist(a, c), dist(b, c)));
		st3 = max(dist(a, b), max(dist(a, c), dist(b, c)));
		st2 = dist(a, b) + dist(a, c) + dist(b, c) - st1 - st3;
	}
};

int main()
{
	ifstream fin("kites.in");
	ofstream fout("kites.out");
	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2, x3, y3;
		fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		Triangle t({x1, y1}, {x2, y2}, {x3, y3}, i);
	}
	return 0;
}
