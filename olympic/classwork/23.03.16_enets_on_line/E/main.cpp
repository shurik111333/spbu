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
	int balance;
};

struct _less
{
	bool operator ()(const Event &e1, const Event &e2)
	{
		return e1.x < e2.x || (e1.x == e2.x && (e1.type < e2.type));/* ||
		                                        (e1.type == e2.type && e1.index < e2.index)));*/
	}
};

int ans[110000];

int main()
{
	ifstream fin("upsolving.in");
	ofstream fout("upsolving.out");
	int n, m;
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);
	fin >> n;
	multiset<Event, _less> events;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		fin >> a >> b;
		events.insert({min(a, b), 0, i, 1});
		//events.insert({min(a, b), 1, i, 0});
		events.insert({max(a, b), 2, i, -1});
	}
	/*for (int i = 0; i < m; i++)
	{
		int a;
		fin >> a;
		events.insert({a, 1, i, 0});
	}*/
	int b = 0;
	stack<int> open;
	stack<int> close;
	for (Event e : events)
	{
		while (!close.empty() && open.top().color == close.top().color)
		{
			open.pop();
			close.pop();
		}
		if (e.type == 0)
		{
			open.push(e.index);
		}
		else
		{
			close.push(e.index);
			ans[e.index] = b;
		}
		b += e.balance;
	}
	for (int i = 0; i < n; i++)
	{
		fout << ans[i] << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
