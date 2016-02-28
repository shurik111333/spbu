#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int a[110000] = {};
int n;

class SegmentTree
{
private:
	long long *tree;
	int size;
	int count;
	
	int min(int a, int b)
	{
		return a > b ? a : b;
	}
	
	void update(int i)
	{
		if (i >= this->count)
			return;
		this->tree[i] = min(this->tree[i * 2], this->tree[i * 2 + 1]);
	}
	
public:
	
	SegmentTree(int count, int *values)
	{
		this->count = 1;
		while (this->count < count)
		{
			this->count *= 2;
		}
		size = this->count * 2;
		tree = new long long[size + 1];
		for (int i = this->count; i < size; i++)
		{
			if (i - this->count < count)
				tree[i] = values[i - this->count];
			else
				tree[i] = 0;
		}
		for (int i = this->count - 1; i > 0; i--)
		{
			update(i);
		}
	}
	
	long long sum(int left, int right)
	{
		int l = left + this->count;
		int r = right + this->count;
		long long result = 0;
		while (l <= r)
		{
			if (l % 2 == 1)
			{
				result = min(result, this->tree[l]);
				l++;
			}
			if (r % 2 == 0)
			{
				result = min(this->tree[r], result);
				r--;
			}
			l /= 2;
			r /= 2;
		}
		return result;
	}
	
	void update(int ind, int x)
	{
		this->tree[ind + this->count] = x;
		for (int i = (ind + this->count) / 2; i > 0; i /= 2)
		{
			update(i);
		}
	}
};

long long f(int k, SegmentTree &tree)
{
	int q = n / k;
	long long res = 0;
	for (int i = 0; i < q; i++)
	{
		/*long long max1 = 0;
		for (int j = k * i; j < k * (i + 1); j++)
		{
			if (max1 < a[j])
				max1 = a[j];
		}*/
		res += tree.sum(k * i, k * i + k - 1) + 1;
	}
	if ((n % k) != 0)
	{
		//long long max1 = 0;
		res += tree.sum(k * q, n - 1) + 1;
	}
	return res - 1;
}

long long f1(int k)
{
	int q = n / k;
	long long res = 0;
	for (int i = 0; i < q; i++)
	{
		long long max1 = 0;
		for (int j = k * i; j < k * (i + 1); j++)
		{
			if (max1 < a[j])
				max1 = a[j];
		}
		res += max1 + 1;
	}
	if ((n % k) != 0)
	{
		long long max1 = 0;
		for (int j = k * q; j < n; j++)
		{
			if (max1 < a[j])
				max1 = a[j];
		}
		res += max1 + 1;
	}
	return res - 1;
}

int main()
{
	/*long long sum = 0;
	int n = 100000;
	for (int i = 1; i <= n; i++)
	{
		sum += n / i;
	}
	cout << sum << endl;
	return 0;*/
	//ifstream fin("in.txt");
	//ofstream fout("out.txt");
	int w;
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	
	//cout << result << endl;
	
	/*while (true)
	{
		n = rand() % 100000 + 1;
		w = rand() % 1000000000 + 1;
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % w + 1;
		}*/
		SegmentTree tree(n, a);
		int res = 0;
		//int result = 0;
		for (int i = 1; i <= n; i++)
		{
			long long x = f(i, tree);
			//long long x1 = f1(i);
			if (x <= w)
			{
				res = i;
				break;
			}
		}
		cout << res;
		
		/*for (int i = 1; i <= n; i++)
		{
			long long x = f1(i);
			if (x <= w)
			{
				result = i;
				break;
			}
		}
		if (result != res)
		{
			fout << n << " " << w << endl;
			for (int i = 0; i < n; i++)
			{
				fout << a[i] << " ";
			}
			fout << endl;
			fout << "bin: " << res << endl;
			fout << "lin: " << result << endl;
			break;
		}
	}*/
	return 0;
}

