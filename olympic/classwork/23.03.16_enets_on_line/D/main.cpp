#include <iostream>
#include <fstream>
#include <set>
#include <stack>

using namespace std;

const int openB = 1;
const int closeB = 0;

struct Event
{
	int x;
	int type;
	int index;
	int color;
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
		if (e1.x != e2.x)
			return e1.x < e2.x;
		/*if (e1.type == e2.type)
			return e1.index < e2.index;*/
		//return e1.index < e2.index;
		if (e1.type == e2.type)
			if (e1.type == openB)
				return e1.index > e2.index;
			else
				return e1.index < e2.index;
		//return e1.index > e2.index;
		return e1.type > e2.type;
		/*if (e1.type == openB)
			return e1.index > e2.index;
		else
			return e1.index < e2.index;*/

	}
	bool operator ()(const Seg &s1, const Seg &s2)
	{
		return s1.x < s2.x || (s1.x == s2.x && (s1.y < s2.y ||
		                                        (s1.y == s2.y && s1.ind < s2.ind)));
	}
};

int ans[51000];
stack<Event> open;
stack<Event> close;

void push()
{
	while (!close.empty() && open.top().color == close.top().color && open.top().x <= close.top().x)
	{
		open.pop();
		close.pop();
	}
}

int main()
{
	ifstream fin("paint.in");
	ofstream fout("paint.out");
	int n, k, m;
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);
	fin >> n >> k >> m;
	for (int i = 0; i <= k; i++)
	{
		ans[i] = 0;
	}
	multiset<Event, _less> events;
	for (int i = 0; i < m; i++)
	{
		int c, a, b;
		fin >> c >> a >> b;
		events.insert({a, openB, i, c});
		events.insert({b, closeB, i, c});
	}
	//Event last = {-1, -1, -1};
	for (Event e : events)
	{
		push();
		if (e.type == openB)
		{
			//if (last.index == -1 || last.x != e.x)
			{
				if (open.empty())
				{
					open.push(e);
					continue;
				}
				if (open.top().color != e.color)
				{
					ans[open.top().color] += e.x - open.top().x;
					if (open.top().index < e.index)
					{
						Event prev = open.top();
						open.pop();
						open.push({e.x, openB, prev.index, prev.color});
						open.push(e);
					}
					else
					{
						//close.push({e.x - 1, closeB, open.top().index, open.top().color});
						Event prev = open.top();
						open.pop();
						open.push(e);
						open.push({e.x, openB, prev.index, prev.color});
					}
				}
				else
				{
					ans[e.color] += e.x - open.top().x;
					Event prev = open.top();
					open.pop();
					open.push({e.x, openB, prev.index, prev.color});
					open.push(e);
				}
			}
			/*else
			{

			}*/
		}
		else
		{
			if (open.top().color == e.color)
			{
				ans[e.color] += e.x - open.top().x + 1;
				open.pop();
				push();
				if (!open.empty())
				{
					Event prev = open.top();
					open.pop();
					open.push({e.x + 1, openB, prev.index, prev.color});
				}
			}
			else
			{
				ans[open.top().color] += e.x - open.top().x;
				close.push(e);
				push();
				//close.push({e.x - 1, closeB, open.top().index, open.top().color});
				Event prev = open.top();
				open.pop();
				open.push({e.x, openB, prev.index, prev.color});
			}
		}
		//last = e;
	}
	for (int i = 1; i <= k; i++)
	{
		fout << ans[i] << " ";
	}
	fin.close();
	fout.close();
	return 0;
}
