#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <limits.h>
#include <set>

using namespace std;

struct Point
{
    int x;
    int y;
    int ind;
    double d;

    Point()
    {
        x = y = d = 0;
    }

    Point(int a, int b, int i)
    {
        x = a;
        y = b;
        ind = i;
        d = INT_MAX;
    }

    bool operator <(const Point &p) const
    {
        return this->d < p.d || (this->d == p.d && this->ind < p.ind);
    }

    bool operator >(const Point &p)
    {
        return this->d > p.d;
    }

    bool operator ==(const Point &p)
    {
        return this->ind == p.ind;
    }
};


double dist(Point &p1, Point &p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main()
{
    ifstream fin("unionday.in");
    ofstream fout("unionday.out");
    int n = 0;
    fin.sync_with_stdio(false);
    fin >> n;
    Point *points = new Point[n];
    set<Point> p;
    set<int> p1;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        fin >> x >> y;
        points[i] = Point(x, y, i);
        points[i].d = dist(points[0], points[i]);
        p.insert(points[i]);
        p1.insert(i);
    }
    double result = 0;
    p1.erase(0);
    p.erase(points[0]);
    while (!p1.empty())
    {
        Point curr = *p.begin();
        p.erase(curr);
        p1.erase(curr.ind);
        result += curr.d;
        for (auto it: p1)
        {
            if (dist(curr, points[it]) < points[it].d)
            {
                Point curr1 = *p.find(points[it]);
                p.erase(curr1);
                curr1.d = dist(curr, curr1);
                points[it].d = curr1.d;
                p.insert(curr1);
            }
        }
    }
    fout << setprecision(15) << result;
    return 0;
}
