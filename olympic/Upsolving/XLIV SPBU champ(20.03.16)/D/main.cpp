#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <list>

using namespace std;

typedef long long ll;

/*struct Tr
{
	Triangle t;
	int count;
};*/

struct Point
{
	int x;
	int y;

	ll operator *(const Point &a)
	{
		return x * a.y - a.x * y;
	}

	Point operator -(const Point &a)
	{
		return {x - a.x, y - a.y};
	}
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
	bool equal;

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
		equal = (st1 == st2) || (st1 == st3) || (st2 == st3);
	}

	int sign()
	{
		if (equal)
			return 1;
		Point p1;
		Point p2;
		if (st1 == dist(a, b))
		{
			if (st2 == dist(b, c))
			{
				p1 = a - b;
				p2 = c - b;
			}
			else
			{
				p1 = b - a;
				p2 = c - a;
			}
		}

		if (st1 == dist(a, c))
		{
			if (st2 == dist(a, b))
			{
				p1 = c - a;
				p2 = b - a;
			}
			else
			{
				p1 = a - c;
				p2 = b - c;
			}
		}

		if (st1 == dist(b, c))
		{
			if (st2 == dist(a, c))
			{
				p1 = b - c;
				p2 = a - c;
			}
			else
			{
				p1 = c - b;
				p2 = a - b;
			}
		}
		return (p1 * p2) < 0 ? -1 : 1;
	}
};

int ans[110000][2] = {};
bool used[110000] = {};
int main()
{
	ifstream fin("kites.in");
	ofstream fout("kites.out");
	int n;
	fin >> n;
	map<ll, map<ll, map<ll, map<int, list<Triangle>>>>> m;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2, x3, y3;
		fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		Triangle t({x1, y1}, {x2, y2}, {x3, y3}, i + 1);
		if (!t.equal)
		{
			if (m[t.st1][t.st2][t.st3][-t.sign()].size() > 0)
			{
				list<Triangle> *l = &m[t.st1][t.st2][t.st3][-t.sign()];
				ans[c][0] = i + 1;
				ans[c][1] = (*l->begin()).index;
				used[ans[c][0]] = true;
				used[ans[c][1]] = true;
				l->erase(l->begin());
				c++;
			}
			else
			{
				m[t.st1][t.st2][t.st3][t.sign()].push_back(t);
			}
		}
		else
		{
			if (m[t.st1][t.st2][t.st3][t.sign()].size() > 0)
			{
				list<Triangle> *l = &m[t.st1][t.st2][t.st3][t.sign()];
				ans[c][0] = i + 1;
				ans[c][1] = (*l->begin()).index;
				used[ans[c][0]] = true;
				used[ans[c][1]] = true;
				l->erase(l->begin());
				c++;
			}
			else
			{
				m[t.st1][t.st2][t.st3][t.sign()].push_back(t);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			ans[c][0] = i;
			c++;
		}
	}
	fout << c << "\n";
	for (int i = 0; i < c; i++)
	{
		fout << ans[i][0] << "-" << ans[i][1] << "\n";
	}
	return 0;
}
