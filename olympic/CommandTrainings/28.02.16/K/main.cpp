#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

struct Point
{
	int x;
	int y;
	
	Point()
	{
		x = 0;
		y = 0;
	}
	
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	bool operator == (const Point &p)
	{
		return this->x == p.x && this->y == p.y;
	}
};

struct Tunnel
{
	Point start;
	Point end;
	
	Tunnel()
	{
		start = Point();
		end = Point();
	}
	
	Tunnel(Point p1, Point p2)
	{
		start = p1;
		end = p2;
	}
	
	bool operator ==(const Tunnel &t)
	{
		return this->start == t.start || this->start == t.end ||
		        this->end == t.end || this->end == t.start;
	}
};

struct Edges
{
	int a;
	int b;
	double dist;
	
	Edges()
	{
		a = 0;
		b = 0;
		dist = 0;
	}
	
	Edges(int a, int b, double d)
	{
		this->a = a;
		this->b = b;
		dist = d;
	}
	
	bool operator < (const Edges &e)
	{
		return this->dist < e.dist;
	}
};

int r[2000] = {};
int p[2000] = {};

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		r[i] = 1;
		p[i] = i;
	}
}

int parent(int v)
{
	if (p[v] == v)
		return v;
	p[v] = parent(p[v]);
	return p[v];
}

void merge(int v, int u)
{
	v = parent(v);
	u = parent(u);
	if (r[v] < r[u])
		p[v] = u;
	else
	{
		p[u] = v;
		if (r[v] == r[u])
			r[u]++;
	}
}

double min(double a, double b)
{
	return a < b ? a : b;
}

double dist(Point &p1, Point &p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double dist(Tunnel &t1, Tunnel &t2)
{
	return min(dist(t1.start, t2.start), min(dist(t1.start, t2.end), min(dist(t1.end, t2.start), dist(t1.end, t2.end))));
}

void sort(int left, int right, Edges a[])
{
	int l = left;
	int r = right;
	double m = a[(l + r) / 2].dist;
	while (l < r)
	{
		while (a[l].dist < m)
		 l++;
		while (a[r].dist > m)
			r--;
		if (l <= r)
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	if (l < right)
		sort(l, right, a);
	if (left < r)
		sort(left, r, a);
}

int main()
{
	ifstream fin("in.txt");
	int n = 0;
	fin >> n;
	Tunnel *t = new Tunnel[n];
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		fin >> a >> b >> c >> d;
		t[i] = Tunnel(Point(a, b), Point(c, d));
	}
	init(n);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (t[i] == t[j])
				merge(parent(i), parent(j));
		}
	}
	double res = 0;
	Edges *e = new Edges[n * n + 1];
	int c = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (parent(i) != parent(j))
			{
				e[c++] = Edges(parent(i), parent(j), dist(t[i], t[j]));
			}
		}
	}
	sort(0, c - 1, e);
	for (int i = 0; i < c; i++)
	{
		if (parent(e[i].a) != parent(e[i].b))
		{
			res += e[i].dist;
			merge(e[i].a, e[i].b);
		}
	}
	cout << setprecision(20) << res;
	return 0;
}

