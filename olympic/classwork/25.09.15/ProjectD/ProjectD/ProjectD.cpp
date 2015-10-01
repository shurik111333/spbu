// ProjectD.cpp: определяет точку входа для консольного приложения.
//

#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("name.in");
ofstream fout("name.out");
int n;
int sum = 'a' + 'b' + 'c';

void gen(char *str, int len, char last1, char last2)
{
	if (len == n)
	{
		for (int i = 0; i < len; i++)
		{
			fout << str[i];
		}
		fout << endl;
		return;
	}
	if (last1 != 'd' && last2 != 'd')
	{
		str[len] = sum - last1 - last2;
		gen(str, len + 1, str[len], last1);
		return;
	}
	for (int i = 'a'; i < 'd'; i++)
	{
		if (i != last1 && i != last2)
		{
			str[len] = i;
			gen(str, len + 1, str[len], last1);
		}
	}
}

int main()
{
	n = 0;
	fin >> n;
	char *str = new char[n + 1];
	memset(str, '\0', n + 1);
	if (n * 6 > 100000)
	{
		fout << "TOO LONG";
	}
	else
	{
		gen(str, 0, 'd', 'd');
	}
	return 0;
}