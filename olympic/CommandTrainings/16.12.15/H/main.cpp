#include <iostream>
#include <fstream>

using namespace std;



int main()
{
	ifstream fin("right-turn-only.in");
	ofstream fout("right-turn-only.out");
	int t;
	fin >> t;
	long long x, y;
	for (int  i = 0; i < t; i++)
	{
		
		fin >> x >> y;
		long long ans = 0;
		if (x == 0 && y==0)
			ans = 0;// << '\n';
		else
		if (x > 0 && y <= 0)
			ans = (x - y + 2);// << '\n';
		else
		if (x >= 0 && y > 0)
			ans = x + y;// << '\n';
		else
		if (x < 0 && y >= 0)
			ans = -x + y + 4;// << '\n';
		else
			ans = -x - y + 4;// << '\n';
		fout << ans << "\n";
	}
	return 0;
}

