#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("dragon.in");
	ofstream fout("dragon.out");
	int n = 0;
	string d;
	
	fin >> n;
	fin >> d;
	
	if (d.length() > n)
		fout << "No solution";
	else
	{
		fout << d;
		for (int i = 0; i < n - d.length(); i++)
			fout << 0;
	}

		return 0;
}