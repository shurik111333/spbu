#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("stacksub.in");
ofstream fout("stacksub.out");

typedef long long ll;

class Matrix
{
public:
	int n;
	int m;
	ll **a;

	Matrix(int n, int m):
	    n(n),
	    m(m)
	{
		a = new ll*[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = new ll[m];
			for (int j = 0; j < m; j++)
				a[i][j] = 0;
		}
	}

	void print(ostream &out)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				out << a[i][j] << " ";
			}
			out << "\n";
		}
	}

	Matrix operator *(const Matrix m)
	{
		Matrix res(n, m.m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m.m; j++)
			{
				for (int k = 0; k < this->m; k++)
				{
					res(i, j) = res(i, j) + a[i][k] * m(k, j);
				}
			}
		}
		return res;
	}

	ll &operator ()(const int i, const int j) const
	{
		return a[i][j];
	}
};
#include <stack>
#include <cctype>

stack<Matrix> func[40];

Matrix addNumber(int num)
{
	Matrix res(7, 7);
	res(0, 0) = 1;
	res(0, 6) = 1;
	res(1, 6) = num;
	for (int i = 2; i < 6; i++)
	{
		res(i, i - 1) = 1;
	}
	res(6, 6) = 1;
//	res.print(cout);
//	cout << endl;
	return res;
}

Matrix operation(char op)
{
	Matrix res(7, 7);
	res(0, 0) = 1;
	res(0, 6) = -1;
	res(1, 2) = 1;
	if (op == '+')
		res(1, 1) = 1;
	else
		res(1, 1) = -1;
	for (int i = 2; i < 5; i++)
	{
		res(i, i + 1) = 1;
	}
	res(6, 6) = 1;
//	res.print(cout);
//	cout << endl;
	return res;
}



Matrix interpret(string s, int &i)
{
	bool used[40] = {};
	Matrix res(7, 7);
	for (int i = 0; i < 7; i++)
	{
		res(i, i) = 1;
	}
	while (i < s.length() && s[i] != ']')
	{
		switch (s[i])
		{
			case '[':
				{
					i++;
					Matrix f = interpret(s, i);
					//res = f * res;
					used[s[i] - 'a'] = true;
					func[s[i] - 'a'].push(f);
					break;
				}
			case '+':
			case '-':
				res = operation(s[i]) * res;
				break;
			default:
				{
					if (isdigit(s[i]))
						res = addNumber(s[i] - '0') * res;
					else
						res = func[s[i] - 'a'].top() * res;
				}
		}
		i++;
	}
	i++;
	for (int i = 0; i < 40; i++)
	{
		if (used[i])
			func[i].pop();
	}
	return res;
}

int main()
{
	string s;
	fin >> s;
	Matrix ans(7, 1);
	ans(6, 0) = 1;
	int i = 0;
	Matrix m = interpret(s, i);
	ans = m * ans;
	fout << ans(0, 0) << "\n";
	for (int i = 1; i <= ans(0, 0); i++)
	{
		fout << ans(i, 0) << " ";
	}
	/*fout << endl;
	for (int i = 0; i < 7; i++)
	{
		fout << ans(i, 0) << endl;
	}*/
	return 0;
}
