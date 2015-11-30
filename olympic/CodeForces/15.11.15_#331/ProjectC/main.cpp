#include <iostream>
#include <fstream>

using namespace std;

struct Point
{
    int x;
    int y;
    int d;

    Point()
        :x(0), y(0)
    {}

    Point(int a, int b)
        :x(a), y(b), d(x + y)
    {}

    Point(Point &point)
        :x(point.x), y(point.y), d(point.d)
    {}

    bool operator <(const Point &point)
    {
        return (this->d < point.d || (this->d == point.d && this->x < point.x));
    }
};

Point points[210000];
int w[210000] = {};
Point result[210000];

void swap(Point &p1, Point &p2)
{
    Point tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void qSort(int left, int right)
{
    int l = left;
    int r = right;
    Point cmp = points[(l + r) / 2];
    while (l < r)
    {
        while (points[l] < cmp)
            l++;
        while (cmp < points[r])
            r--;
        if (l <= r)
        {
            swap(points[l], points[r]);
            l++;
            r--;
        }
    }
    if (l < right)
        qSort(l, right);
    if (left < r)
        qSort(left, r);
}

const int mind = -100000;

int main()
{
    ifstream fin("file.in");
    int n;
    fin >> n;
    bool res = true;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        fin >> x >> y;
        points[i] = Point(x, y);
    }
    for (int i = 0; i < n; i++)
    {
        fin >> w[i];
    }
    qSort(0, n - 1);
    int p[300000] = {};
    int d = 0;
    int ind = 0;
    while (ind < n)
    {
        int newInd = 0;
        for (int i = ind; points[i].d == d; i++)
        {
            p[points[i].y - points[i].x - mind] = 1;
            newInd = i;
        }
        for (int i = ind; points[i].d == d; i++)
        {
            if (p[w[i] - mind] == 0)
            {
                res = false;
                break;
            }
            else
            {
                result[i] = Point(d - (d + w[i]) / 2, (w[i] + d) / 2);
                p[w[i] - mind] = 0;
            }
        }
        if (!res)
            break;
        ind = newInd + 1;
        d++;
    }
    if (!res)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << result[i].x << " " << result[i].y << "\n";
    }
    return 0;
}

