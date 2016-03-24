#include <iostream>
#include <fstream>
#include <set>

using namespace std;

struct Event
{
	int x;
	int type;
	int index;
	int balance;
};

struct _less
{
	bool operator ()(const Event &e1, const Event &e2)
	{
		return e1.x < e2.x || (e1.x == e2.x && e1.type < e2.type);
	}
};

int ans[110000];

int main()
{
	ifstream fin("segments.in");
	ofstream fout("segments.out");
	int n, m;
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);
	fin >> n >> m;
	multiset<Event, _less> events;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		fin >> a >> b;
		events.insert({min(a, b), 0, i, 1});
		events.insert({max(a, b), 2, i, -1});
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		fin >> a;
		events.insert({a, 1, i, 0});
	}
	int b = 0;
	for (Event e : events)
	{
		if (e.type == 1)
		{
			ans[e.index] = b;
		}
		b += e.balance;
	}
	for (int i = 0; i < m; i++)
	{
		fout << ans[i] << " ";
	}
	fin.close();
	fout.close();
	return 0;
}
