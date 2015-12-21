#include <iostream>
#include <fstream>

using namespace std;

class Fenvik
{
public:
	int n;
	long long *tree;
	
	Fenvik()
	    :n(0), tree(nullptr)
	{}
	
	Fenvik(int n)
	    :n(n)
	{
		tree = new long long[n];
		for (int i = 0; i < n; i++)
		{
			tree[i] = 0;
		}
	}
	
	void update(int pos, int x)
	{
		for (int i = pos; i < n; i = (i + 1) | i)
		{
			tree[i] += x;
		}
	}
	
	long long sum(int l, int r)
	{
		long long result = 0;
		for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
		{
			result += tree[i];
		}
		for (int i = l - 1; i >= 0; i = (i & (i + 1)) - 1)
		{
			result -= tree[i];
		}
		return result;
	}
};

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	ifstream fin("fenwick.in");
	ofstream fout("fenwick.out");
	int n = 0, k = 0;
	fin >> n >> k;
	Fenvik *t = new Fenvik[n];
	for (int i = 0; i < n; i++)
	{
		t[i] = Fenvik(n);
	}
	char c[5];
	for (int i = 0; i < k; i++)
	{
		int a, b;
		fin >> c >> a >> b;
		if (c[0] == 'A')
		{
			for (int i = a - 1; i < n; i = (i + 1) | i)
				t[i].update(b - 1, 1);
		}
		else
		{
			int x, y;
			fin >> x >> y;
			int x1 = min(a, x) - 1;
			int y1 = min(b, y) - 1;
			int x2 = a + x - x1 - 2;
			int y2 = b + y - y1 - 2;
			long long sum = 0;
			for (int i = x2; i >= 0; i = ((i + 1) & i) - 1)
				sum += t[i].sum(y1, y2);
			for (int i = x1 - 1; i >= 0; i = ((i + 1) & i) - 1)
				sum -= t[i].sum(y1, y2);
			fout << sum << "\n";
		}
	}
	return 0;
}

