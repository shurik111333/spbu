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

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double d[5100] = {};

struct _less{
    bool operator()(int a, int b)
    {
        return (d[a] < d[b]) || (d[a] == d[b] && a < b);
    }
};

int main()
{
    ifstream fin("unionday.in");
    ofstream fout("unionday.out");
    int n = 0;
    fin.sync_with_stdio(false);
    fin >> n;
    int x[5100] = {}, y[5100] = {};
    //set<int, _less> p;
    //set<int> p1;
    for (int i = 0; i < n; i++)
    {
        fin >> x[i] >> y[i];
        d[i] = dist(x[i], y[i], x[0], y[0]);
        //p.insert(i);
        //p1.insert(i);
    }
    double result = 0;
    //p1.erase(0);
   // p.erase(0);
    int curr = 0;
    int min1 = 0;
    for (int i = 0; i < n; i++)
    {
        //int curr = *p.begin();
        //p.erase(curr);
        //p1.erase(curr);
        result += d[curr];
        d[curr] = -1;
        min1 = -1;
        for (int it = 0; it < n; it++)
        {
            if (d[it] != -1)
            {
                if (dist(x[curr], y[curr], x[it], y[it]) < d[it])
                {
                    //Point curr1 = *p.find(points[it]);
                    //p.erase(it);
                    //curr1.d = dist(curr, curr1);
                    d[it] = dist(x[curr], y[curr], x[it], y[it]);
                    //p.insert(it);
                }
                if (min1 == -1 || (d[it] < d[min1]))
                {
                    min1 = it;
                }
            }
        }
        curr = min1;
    }
    fout << setprecision(15) << result;
    return 0;
}
