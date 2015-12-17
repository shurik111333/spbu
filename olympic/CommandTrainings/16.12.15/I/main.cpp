#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("forbidden-triples.in");
	ofstream fout ("forbidden-triples.out");
	long long n;
	
	fin >> n;
	long long s = 0;
	if (n % 2 == 0)
		s += n / 2;
	else
		s += n;
	s *= 3;
	//s++;
	s += n*(n - 1)*6;
	/*for (int i=0; i < n; i += 2)
		s+=i;
	fout << (long long)((long long)(s)*6+(long long)(n-1)*3+1);*/
	return 0;
}

