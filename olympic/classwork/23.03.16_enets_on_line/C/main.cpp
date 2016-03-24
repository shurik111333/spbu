#include <iostream>
#include <fstream>
#include <set>
#include <stack>

using namespace std;

struct Event
{
	int x;
	int type;
	int index;
};

struct Seg
{
	int x;
	int y;
	int ind;
};

struct _less
{
	bool operator ()(const Event &e1, const Event &e2)
	{
		return e1.x < e2.x || (e1.x == e2.x && (e1.type < e2.type
		                       || e1.type == e2.type && e1.index < e2.index));
	}
	bool operator ()(const Seg &s1, const Seg &s2)
	{
		return s1.x < s2.x || (s1.x == s2.x && (s1.y < s2.y ||
		                                        (s1.y == s2.y && s1.ind < s2.ind)));
	}
};

Seg ans[110000];

int main()
{
	ifstream fin("cover.in");
	ofstream fout("cover.out");
	int n, m;
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);
	fin >> m;
	multiset<Seg, _less> events;
	int i = 0;
	while (true)
	{
		int a = 0, b = 0;
		fin >> a >> b;
		if (a == 0 && b == 0)
			break;
		events.insert({a, b, i});
		i++;
	}
	int p = 0;
	int c = 0;
	ans[0].ind = -1;
	ans[c].y = -1;
	//Seg last{-1, -1, -1};
	for (Seg s : events)
	{
		if (ans[c].y >= m)
			break;
		if (s.x > p)
		{
			if (ans[c].ind == -1)
			{
				fout << "No solution";
				return 0;
			}
			//ans[c] = last;
			p = ans[c].y;
			c++;
			ans[c] = {-1, -1, -1};
		}
		if (s.x <= p)
		{
			if (s.y > ans[c].y)
			{
				//last = s;
				ans[c] = s;
				//p = s.y;
			}
			//p = last.y;
		}
	}
	/*if (last.ind != -1)
	{
		ans[c] = last;
		c++;
		p = last.y;
	}*/
	if (ans[c].y < m)
	{
		fout << "No solution";
		return 0;
	}
	c++;
	fout << c << "\n";
	for (int i = 0; i < c; i++)
	{
		fout << ans[i].x << " " << ans[i].y << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
