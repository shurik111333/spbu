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

struct _less
{
	bool operator ()(const Event &e1, const Event &e2)
	{
		return e1.x < e2.x || (e1.x == e2.x && e1.type < e2.type);
	}
};

int l[55000];
int r[55000];

int main()
{
	ifstream fin("merge.in");
	ofstream fout("merge.out");
	int n, m;
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);
	fin >> n;
	multiset<Event, _less> events;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		fin >> a >> b;
		events.insert({min(a, b), 0, i});
		events.insert({max(a, b), 2, i});
	}
	stack<int> s;
	int c = 0;
	for (Event e : events)
	{
		if (e.type == 0)
			s.push(e.x);
		else
		{
			if (s.size() == 1)
			{
				l[c] = s.top();
				r[c] = e.x;
				c++;
			}
			s.pop();
		}
	}
	fout << c << "\n";
	for (int i = 0; i < c; i++)
	{
		fout << l[i] << " " << r[i] << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
